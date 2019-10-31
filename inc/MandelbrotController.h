#ifndef MANDELBROT_CONTROLLER_H
#define MANDELBROT_CONTROLLER_H

#define MAX_MANDELBROT_ITERS 4000

class CMandelbrotController
{
private:
  static unsigned int m_colorTable[MAX_MANDELBROT_ITERS+1];

  struct Initializer
  {
    Initializer(void)
    {
      int step = 0x00ffffff / MAX_MANDELBROT_ITERS;
      for (int i = 0; i < MAX_MANDELBROT_ITERS; i++)
      {
        m_colorTable[i] = 0x00ffffff - step*i;
      }
      m_colorTable[MAX_MANDELBROT_ITERS] = 0x00000000;
    }
  };

  static Initializer m_initializer;

  CMandelbrotController(){};
  ~CMandelbrotController(){};

public:
  static unsigned int GetMandelbrotColor(long double x0, long double y0);  
};



#endif