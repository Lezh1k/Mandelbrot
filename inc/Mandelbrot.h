#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>

void MandelbrotInitColorTable(void);

void MandelbrotResetBounds(long double *lx,
                           long double *rx,
                           long double *ty,
                           long double *by);

uint32_t MandelbrotGetColor(long double x0,
                            long double y0);


#endif
