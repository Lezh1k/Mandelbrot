#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>

struct MandelbrotInitializer;
extern MandelbrotInitializer mandelbrotInitializer;

void MandelbrotResetBounds(long double *lx,
                           long double *rx,
                           long double *ty,
                           long double *by);

void MandelbrotFillLine(long double lx,
                        long double dx,
                        long double y,
                        uint32_t yix,
                        uint32_t width,
                        uint32_t *dst);


#endif
