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

  uint32_t *Data(void) const {return m_data;}
  uint32_t DataLenBytes(void) const {return m_width*m_height*sizeof(uint32_t);}

private:
  uint32_t m_width;
  uint32_t m_height;
  uint32_t *m_data;

  double m_lx, m_rx; //left x, right x
  double m_ty, m_by; //top y, bottom y

  pfResetBounds m_pfResetBounds; //bounds for different types of fractals are differ
  pfGetColor m_pfGetColor;
};

#endif // FRACTALSMODEL_H
