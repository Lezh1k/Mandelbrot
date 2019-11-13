#include <complex>

#include "Newton.h"
#include "Commons.h"

#define MAX_ITERS_COUNT 0xff

void
NewtonInitColorTable() {

}

// f(x) = sin(x) - 1
// f'(x) = cos(x)
uint32_t NewtonGetColor( long double zx,
                         long double zy ) {
  uint32_t iterCount = 0;
  static const long double maxT = 1e+6l;
  static const long double minT = 1e-6l;
  
  std::complex<long double> z(zx, zy);
  std::complex<long double> t = z;
  std::complex<long double> d = t;

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
NewtonResetBounds(long double *lx,
                  long double *rx,
                  long double *ty,
                  long double *by) {
  *lx = -4.15L;
  *by = -1.0L;
  *rx = *ty = 1.0L;
}
///////////////////////////////////////////////////////

