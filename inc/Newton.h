#ifndef NEWTON_H
#define NEWTON_H
#include <stdint.h>

void NewtonResetBounds(long double *lx,
                       long double *rx,
                       long double *ty,
                       long double *by);

uint32_t NewtonGetColor(long double cx,
                        long double cy);


#endif
