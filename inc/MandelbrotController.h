#ifndef MANDELBROT_CONTROLLER_H
#define MANDELBROT_CONTROLLER_H

#define MAX_MANDELBROT_ITERS 4000

#include <stdint.h>

class CMandelbrotController
{
private:
  static uint32_t m_colorTable[MAX_MANDELBROT_ITERS+1];
  struct Initializer
  {
    Initializer(void) {
      uint32_t step = 0x00ffffff / MAX_MANDELBROT_ITERS;
      for (uint32_t i = 0; i < MAX_MANDELBROT_ITERS; ++i)
        m_colorTable[i] = 0x00ffffff - step*i;
      m_colorTable[MAX_MANDELBROT_ITERS] = 0x00000000;
    }
  };

  static Initializer m_initializer;

  CMandelbrotController() = delete;
  ~CMandelbrotController() = delete;

public:
  static uint32_t GetMandelbrotColor(long double x0, long double y0);
};



#endif
