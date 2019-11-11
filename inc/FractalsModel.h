#ifndef FRACTALSMODEL_H
#define FRACTALSMODEL_H

#include <stdint.h>

enum FractalType {
  FT_MANDELBROT = 0,
  FT_NEWTON
};

typedef void (*pfResetBounds)(long double *lx, long double *rx, long double *ty, long double *by) ;
typedef uint32_t (*pfGetColor)(long double x, long double y);

class FractalsModel {
public:
  FractalsModel() = delete;
  FractalsModel(uint32_t width, uint32_t height);
  ~FractalsModel();

  void SetFractalType(FractalType t);
  void SetCenter(uint32_t x, uint32_t y, bool grow);
  void Update();

private:
  uint32_t m_width;
  uint32_t m_height;
  uint32_t *m_data;

  long double m_lx, m_rx; //left x, right x
  long double m_ty, m_by; //top y, bottom y

  pfResetBounds m_pfResetBounds;
  pfGetColor m_pfGetColor;
};

#endif // FRACTALSMODEL_H
