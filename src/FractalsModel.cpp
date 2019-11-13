#include "FractalsModel.h"
#include "Mandelbrot.h"
#include "Newton.h"
#include "Commons.h"

FractalsModel::FractalsModel(uint32_t width,
                             uint32_t height) :
  m_width(width),
  m_height(height),
  m_data(nullptr) {
  m_data = new uint32_t[width*height];
}
///////////////////////////////////////////////////////

FractalsModel::~FractalsModel() {
  delete m_data;
  m_data = nullptr;
}
///////////////////////////////////////////////////////

void
FractalsModel::SetFractalType(FractalType t) {
  static pfResetBounds rst[] = {MandelbrotResetBounds, NewtonResetBounds};
  static pfGetColor gcl[] = {MandelbrotGetColor, NewtonGetColor};
  m_pfResetBounds = rst[t];
  m_pfGetColor = gcl[t];
  m_pfResetBounds(&m_lx, &m_rx, &m_ty, &m_by);
}
///////////////////////////////////////////////////////

void
FractalsModel::SetPOI(uint32_t x,
                      uint32_t y,
                      bool grow) {
  //  long double dx = p2p_distance(m_rx, m_lx) / m_width;
  //  long double dy = p2p_distance(m_ty, m_by) / m_height;
  long double dx = (m_rx - m_lx) / m_width;
  long double dy = (m_ty - m_by) / m_height;
  long double coef = grow ? 4.0l : 0.95l;

  long double cx0, cy0;
  cx0 = m_lx + x*dx;
  cy0 = m_ty - y*dy;

  m_rx = cx0 + (m_width / coef)*dx;
  m_lx = cx0 - (m_width / coef)*dx;

  m_ty = cy0 + (m_height / coef)*dy;
  m_by = cy0 - (m_height / coef)*dy;
}
///////////////////////////////////////////////////////

void
FractalsModel::Update() {
  //  long double dx = p2p_distance(m_rx, m_lx) / m_width;
  //  long double dy = p2p_distance(m_ty, m_by) / m_height;
  long double dx = (m_rx - m_lx) / m_width;
  long double dy = (m_ty - m_by) / m_height;

  long double y = m_ty;
  uint32_t *d = m_data;

  for (uint32_t yi = 0; yi < m_height; ++yi, y -= dy) {
    long double x = m_lx;
    for (uint32_t xi = 0; xi < m_width; ++xi, x += dx)
      *d++ = m_pfGetColor(x, y);
  }

  // invert colors for main axis
  d = &m_data[m_width / 2];
  for (uint32_t yi = 0; yi < m_height; ++yi, d += m_width)
    *d ^= 0xffffffff;
  d = &m_data[m_height/2 * m_width];
  for (uint32_t xi = 0; xi < m_width; ++xi)
    *d++ ^= 0xffffffff;
  //
}
///////////////////////////////////////////////////////
