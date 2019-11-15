#include "FractalsModel.h"
#include "Mandelbrot.h"
#include "Newton.h"
#include "Commons.h"

#include <chrono>

FractalsModel::FractalsModel(uint32_t width,
                             uint32_t height) :
  m_width(width),
  m_height(height),
  m_data(nullptr) {
  uint32_t w = (width + 16) & static_cast<uint32_t>(~15); //align to 16
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
  static pfFillLine fl[] = {MandelbrotFillLine, NewtonFillLine};

  m_pfGetColor = gcl[t];
  m_pfFillLine = fl[t];

  rst[t](&m_lx, &m_rx, &m_ty, &m_by);
}
///////////////////////////////////////////////////////

void
FractalsModel::SetPOI(uint32_t x,
                      uint32_t y,
                      bool grow) {
  //  double dx = p2p_distance(m_rx, m_lx) / m_width;
  //  double dy = p2p_distance(m_ty, m_by) / m_height;
  double dx = (m_rx - m_lx) / m_width;
  double dy = (m_ty - m_by) / m_height;
  double coef = grow ? 4.0 : 0.95;

  double cx0, cy0;
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
  //  double dx = p2p_distance(m_rx, m_lx) / m_width;
  //  double dy = p2p_distance(m_ty, m_by) / m_height;
  double dx = (m_rx - m_lx) / m_width;
  double dy = (m_ty - m_by) / m_height;

  //schedule dynamic because rows could be processed in different time
  #pragma omp parallel for schedule(dynamic, 1)
  for (uint32_t yi = 0; yi < m_height; ++yi) {
    m_pfFillLine(m_lx, dx, m_ty-yi*dy, yi, m_width, m_data);
  }

  // invert colors for main axis
  uint32_t *d = &m_data[m_width / 2];
  for (uint32_t yi = 0; yi < m_height; ++yi, d += m_width)
    *d ^= 0xffffffff;
  d = &m_data[m_height/2 * m_width];
  for (uint32_t xi = 0; xi < m_width; ++xi)
    *d++ ^= 0xffffffff;
  //
}
///////////////////////////////////////////////////////
