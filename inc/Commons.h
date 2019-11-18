#ifndef COMMONS_H
#define COMMONS_H

#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <type_traits>

long double p2p_distance(long double a, long double b);

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y, int ulp) {
  // эпсилон нужно отмасштабировать на величину наибольшего значения
  // и умножить на желаемую точность в ULP (units in the last place)
  return std::abs(x-y) <= std::numeric_limits<T>::epsilon()
      * std::max(std::abs(x), std::abs(y))
      * ulp;
}
///////////////////////////////////////////////////////

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
numeric_equal(T x, T y) {
  return std::abs(x-y) <= std::numeric_limits<T>::epsilon();
}
///////////////////////////////////////////////////////

#endif 
