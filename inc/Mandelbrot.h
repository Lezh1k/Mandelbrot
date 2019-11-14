#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>

void MandelbrotInitColorTable(void);

void MandelbrotResetBounds(double *lx,
                           double *rx,
                           double *ty,
                           double *by);

uint32_t MandelbrotGetColor(double x0,
                            double y0);


#endif
