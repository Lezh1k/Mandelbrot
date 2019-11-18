#ifndef NEWTON_H
#define NEWTON_H
#include <stdint.h>

struct NewtonInitializer;
extern NewtonInitializer newtonInitializer;

void NewtonResetBounds(long double *lx,
                       long double *rx,
                       long double *ty,
                       long double *by);



void NewtonFillLine(long double lx,
                    long double dx,
                    long double y,
                    uint32_t yix,
                    uint32_t width,
                    uint32_t *dst);


#endif
