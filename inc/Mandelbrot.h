#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdint.h>

struct MandelbrotInitializer;
extern MandelbrotInitializer mandelbrotInitializer;

void MandelbrotResetBounds(double *lx,
                           double *rx,
                           double *ty,
                           double *by);

void MandelbrotFillLine(double lx,
                        double dx,
                        double y,
                        uint32_t yix,
                        uint32_t width,
                        uint32_t *dst);


#endif
