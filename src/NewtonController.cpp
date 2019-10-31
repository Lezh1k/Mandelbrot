#include "stdafx.h"
#include "NewtonController.h"
#include "Commons.h"
#include <complex>

// f(x) = sin(x) - 1
// f'(x) = cos(x)
unsigned int CNewtonController::GetNewtonFractalsColor( long double zx, long double zy )
{
  int iterCount = 0;
  
  static const long double maxT = 1e+6;
  static const long double minT = 1e-6;
  std::complex<long double> z(zx, zy);
  std::complex<long double> t = z;
  std::complex<long double> d = t;

  while (iterCount < 0xff && abs(z) < maxT && abs(d) > minT)
  {
    z = z - sin(z) / cos(z);
    d = t-z;
    t = z; 
    iterCount++;
  }
 
  unsigned int result = 0x00ffffff;
  result &= ((iterCount * 8 % 0xff) << 16) | ((iterCount * 7 % 0xff) << 8) | (iterCount * 6 % 0xff);
  result &= 0x00ffffff;
  return result;
}
//////////////////////////////////////////////////////////////////////////