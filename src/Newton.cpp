#include <complex>

#include "Newton.h"
#include "Commons.h"

#define MAX_ITERS_COUNT 0xff

void
NewtonInitColorTable() {

}

// f(x) = sin(x) - 1
// f'(x) = cos(x)
uint32_t NewtonGetColor( double zx,
                         double zy ) {
  uint32_t iterCount = 0;
  static const double maxT = 1e+6l;
  static const double minT = 1e-6l;
  
  std::complex<double> z(zx, zy);
  std::complex<double> t = z;
  std::complex<double> d = t;

  while (iterCount < MAX_ITERS_COUNT && abs(z) < maxT && abs(d) > minT) {
    z = z - sin(z) / cos(z);
    d = t-z;
    t = z;
    ++iterCount;
  }

  uint32_t result = 0;
  result |= ((iterCount * 8u) & 0xff) << 16u;
  result |= ((iterCount * 7u) & 0xff) << 8u;
  result |= (iterCount * 6u) & 0xff;
  result |= 0xff000000;
  return result;
}
//////////////////////////////////////////////////////////////////////////

void
NewtonResetBounds(double *lx,
                  double *rx,
                  double *ty,
                  double *by) {
  *lx = -4.15L;
  *by = -1.0L;
  *rx = *ty = 1.0L;
}
///////////////////////////////////////////////////////

