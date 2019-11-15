#ifndef NEWTON_H
#define NEWTON_H
#include <stdint.h>

struct NewtonInitializer;
extern NewtonInitializer newtonInitializer;

void NewtonResetBounds(double *lx,
                       double *rx,
                       double *ty,
                       double *by);



void NewtonFillLine(double lx,
                    double dx,
                    double y,
                    uint32_t yix,
                    uint32_t width,
                    uint32_t *dst);


#endif
