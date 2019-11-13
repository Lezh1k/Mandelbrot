#include "Mandelbrot.h"
#include <math.h>

#define MAX_MANDELBROT_ITERS 0xff
static uint32_t m_colorTable[MAX_MANDELBROT_ITERS + 1];

static bool isInMainCardioid(long double x, long double y);

void
MandelbrotInitColorTable() {
  double mid = static_cast<double>(MAX_MANDELBROT_ITERS);
  for (uint32_t i = 0; i < MAX_MANDELBROT_ITERS; ++i) {
    double f = sqrt(i / mid);
    int intens = f * MAX_MANDELBROT_ITERS;
    m_colorTable[i] = 0xff000000 | intens << 16 | intens << 8 | intens;
  }
  m_colorTable[MAX_MANDELBROT_ITERS] = 0xff000000;
}
///////////////////////////////////////////////////////

bool
isInMainCardioid(long double x,
                 long double y) {
  long double q = (x-0.25l)*(x-0.25l) + y*y;
  return q*(q+(x-0.25l)) <= 0.25l * y*y;
// alternative 1.
//  long double p = sqrtl((x-0.25l)*(x-0.25l) + y*y);
//  long double th = atan2l(y, x - 0.25l);
//  long double pc = 0.5l - 0.5l*cosl(th);
//  return p < pc;
// alternative 2.
//  long double p = sqrtl((x-0.25l)*(x-0.25l) + y*y);
//  return x <= p - 2.0l * p*p + 0.25l || (x+1.0l)*(x+1.0l) + y*y <= 1.0l / 16.0l;
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
  if (isInMainCardioid(x0, y0))
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
