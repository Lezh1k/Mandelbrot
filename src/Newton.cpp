#include <complex>

#include "Newton.h"
#include "Commons.h"

#define MAX_ITERS_COUNT 0xff

static uint32_t m_colorTable[MAX_ITERS_COUNT+1];
static uint32_t getColor(long double cx,
                         long double cy);

void
initColorTable() {
  for (uint32_t ic = 0; ic < MAX_ITERS_COUNT; ++ic) {
    m_colorTable[ic] = 0;
    m_colorTable[ic] |= ((ic * 8u) & 0xff) << 16u;
    m_colorTable[ic] |= ((ic * 7u) & 0xff) << 8u;
    m_colorTable[ic] |= (ic * 6u) & 0xff;
    m_colorTable[ic] |= 0xff000000;
  }
  m_colorTable[MAX_ITERS_COUNT] = 0;
}

// f(x) = sin(x) - 1
// f'(x) = cos(x)
uint32_t getColor( long double zx,
                   long double zy ) {
  uint32_t iterCount = 0;
  static const long double maxT = 1e+6;
  static const long double minT = 1e-6;
  
  std::complex<long double> z(zx, zy);
  std::complex<long double> t = z;
  std::complex<long double> d = t;

  while (iterCount < MAX_ITERS_COUNT && abs(z) < maxT && abs(d) > minT) {
    z = z - sin(z) / cos(z);
    d = t-z;
    t = z;
    ++iterCount;
  }

  return m_colorTable[iterCount];
}
//////////////////////////////////////////////////////////////////////////

void
NewtonResetBounds(long double *lx,
                  long double *rx,
                  long double *ty,
                  long double *by) {
  *lx = -4.15;
  *by = -1.0;
  *rx = *ty = 1.0;
}
///////////////////////////////////////////////////////

void
NewtonFillLine(long double lx,
               long double dx,
               long double y,
               uint32_t yix,
               uint32_t width,
               uint32_t *dst) {
  for (uint32_t xi = 0; xi < width; ++xi, lx += dx)
    dst[yix*width+xi] = getColor(lx, y);
}
///////////////////////////////////////////////////////

struct NewtonInitializer {
  NewtonInitializer() {
    initColorTable();
  }
  ~NewtonInitializer() = default;
} newtonInitializer;
