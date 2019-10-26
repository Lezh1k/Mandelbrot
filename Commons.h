#ifndef COMMONS_H
#define COMMONS_H
#include <math.h>

__forceinline long double DISTANCE(long double a, long double b)
{
  return sqrt(pow((a-b), 2.0L));
}

__forceinline BITMAP GetBitmap( HBITMAP hbm )
{
  BITMAP bm;	
  int goRes;
  goRes = ::GetObject( hbm, sizeof( BITMAP ), &bm );
  ATLASSERT(goRes);
  return bm;
}

#endif 