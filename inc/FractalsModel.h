#ifndef FRACTALSMODEL_H
#define FRACTALSMODEL_H

#include <stdint.h>

enum FractalType {
  FT_MANDELBROT = 0,
  FT_NEWTON
};

typedef void (*pfResetBounds)(double *lx,
                              double *rx,
                              double *ty,
                              double *by) ;

typedef uint32_t (*pfGetColor)(double x,
                               double y);

typedef void (*pfFillLine)(double lx,
                           double dx,
                           double y,
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
  const uint32_t *Line(uint32_t rowIx) const {return &m_data[m_width*rowIx];}

  uint32_t Width(void) const {return m_width;}
  uint32_t Height(void) const {return m_height;}

private:
  uint32_t m_width;
  uint32_t m_height;
  uint32_t *m_data;

  double m_lx, m_rx; //left x, right x
  double m_ty, m_by; //top y, bottom y

  pfGetColor m_pfGetColor;
  pfFillLine m_pfFillLine;
};

#endif // FRACTALSMODEL_H
