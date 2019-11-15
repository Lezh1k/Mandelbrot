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

void MandelbrotFillLine(double lx,
                        double dx,
                        double y,
                        uint32_t yix,
                        uint32_t width,
                        uint32_t *dst);


#endif
