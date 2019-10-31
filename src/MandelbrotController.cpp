#include "MandelbrotController.h"

uint32_t CMandelbrotController::m_colorTable[MAX_MANDELBROT_ITERS + 1];
CMandelbrotController::Initializer CMandelbrotController::m_initializer;
///////////////////////////////////////////////////////

uint32_t CMandelbrotController::GetMandelbrotColor(long double x0,
                                                   long double y0) {
  long double  x, y;
  if (x0 < -2.5l || x0 > 1.0l || y0 < -1.0l || y0 > 1.0l) //?
    return m_colorTable[0];
  
  unsigned int iterCount = 0;
  x = y = 0.0l;

  while (x*x + y*y < 4.0l && iterCount < MAX_MANDELBROT_ITERS) {
    long double xtmp = x*x - y*y + x0;
    y = 2 * x*y + y0;
    x = xtmp;
    ++iterCount;
  }

  return m_colorTable[iterCount];
}
///////////////////////////////////////////////////////
