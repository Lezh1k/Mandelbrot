#include "Mandelbrot.h"
#include <math.h>

#define MAX_MANDELBROT_ITERS 4000
static uint32_t m_colorTable[MAX_MANDELBROT_ITERS + 1];

static bool isInMainCardioid(long double x, long double y);

void
MandelbrotInitColorTable() {
  uint32_t step = 0x00ffffff / MAX_MANDELBROT_ITERS;
  for (uint32_t i = 0; i < MAX_MANDELBROT_ITERS; ++i)
    m_colorTable[i] = 0xff000000 | (0x00ffffff - step*i);
  m_colorTable[MAX_MANDELBROT_ITERS] = 0xff000000;
}
///////////////////////////////////////////////////////

bool
isInMainCardioid(long double x,
                 long double y) {
  long double p = sqrtl((x-0.25l)*(x-0.25l) + y*y);
  long double th = atan2l(y, x - 0.25l);
  long double pc = 0.5l - 0.5l*cosl(th);
  return p < pc;
}
///////////////////////////////////////////////////////

uint32_t
MandelbrotGetColor(long double x0,
                   long double y0) {
  if (x0 < -2.5l || x0 > 1.0l || y0 < -1.0l || y0 > 1.0l) //?
    return m_colorTable[0];
  
  long double  x, y;
  unsigned int ic = 0; //iterations count
  x = y = 0.0l;
  if (isInMainCardioid(x, y))
    return m_colorTable[MAX_MANDELBROT_ITERS];

  /*
   * Xn+1 = Xn^2 - Yn^2 + X0
   * Yn+1 = 2*Xn*Yn + Y0
  */
  while (x*x + y*y < 4.0l && ic < MAX_MANDELBROT_ITERS) {
    long double xtmp = x*x - y*y + x0;
    y = 2 * x*y + y0;
    x = xtmp;
    ++ic;
  }
  return m_colorTable[ic];
}
///////////////////////////////////////////////////////

void
MandelbrotResetBounds(long double *lx,
                      long double *rx,
                      long double *ty,
                      long double *by) {
  *lx = -2.5L;
  *by = -1.0L;
  *rx = *ty = 1.0L;
}
///////////////////////////////////////////////////////
