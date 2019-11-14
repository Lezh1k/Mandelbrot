#ifndef NEWTON_H
#define NEWTON_H
#include <stdint.h>

void NewtonInitColorTable();

void NewtonResetBounds(double *lx,
                       double *rx,
                       double *ty,
                       double *by);

uint32_t NewtonGetColor(double cx,
                        double cy);


#endif
