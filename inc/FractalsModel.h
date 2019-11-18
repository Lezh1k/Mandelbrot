#ifndef FRACTALSMODEL_H
#define FRACTALSMODEL_H

#include <stdint.h>

enum FractalType {
  FT_MANDELBROT = 0,
  FT_NEWTON
};

typedef void (*pfResetBounds)(long double *lx,
                              long double *rx,
                              long double *ty,
                              long double *by) ;

typedef uint32_t (*pfGetColor)(long double x,
                               long double y);

typedef void (*pfFillLine)(long double lx,
                           long double dx,
                           long double y,
                           uint32_t yix,
                           uint32_t width,
                           uint32_t *dst);

class FractalsModel {
public:
  FractalsModel() = delete;
  FractalsModel(const FractalsModel&) = delete;
  FractalsModel(uint32_t width,
                uint32_t height);
  ~FractalsModel();

  void SetFractalType(FractalType t);

  void SetPOI(uint32_t x,
              uint32_t y,
              bool grow);

  void Update();
  const uint32_t *Data(void) const {return m_data;}  
  const uint32_t *Line(uint32_t y) const {return &m_data[m_width*y];}

private:
  uint32_t m_width;
  uint32_t m_height;
  uint32_t *m_data;

  long double m_lx, m_rx; //left x, right x
  long double m_ty, m_by; //top y, bottom y

  pfFillLine m_pfFillLine;
};

#endif // FRACTALSMODEL_H
