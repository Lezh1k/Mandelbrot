#include "stdafx.h"
#include "MandelbrotController.h"

unsigned int CMandelbrotController::m_colorTable[MAX_MANDELBROT_ITERS + 1];
CMandelbrotController::Initializer CMandelbrotController::m_initializer;


/**********/

//////////////////////////////////////////////////////////////////////////

unsigned int CMandelbrotController::GetMandelbrotColor(long double x0, long double y0)
{
  long double  x, y, xtmp;

  if (x0 < -2.5 || x0 > 1.0 || y0 < -1.0 || y0 > 1.0)
    return m_colorTable[0];
  
  unsigned int iterCount = 0;
  x = y = 0.0;

  while (x*x + y*y < 4 && iterCount < MAX_MANDELBROT_ITERS)
  {
    xtmp = x*x - y*y + x0;
    y = 2 * x*y + y0;
    x = xtmp;
    ++iterCount;
  }

  return m_colorTable[iterCount];
}

//////////////////////////////////////////////////////////////////////////
