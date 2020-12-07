#ifndef SIMPSON_FUNCTORS_HPP
#define SIMPSON_FUNCTORS_HPP

#include "simpson_functors.hpp"

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>

template <class F, class T>
T simpson(const T a, const T b, unsigned int bins, const F &func)
{

  assert(bins > 0);
  const T dr = (b - a) / (2. * bins);

  T I2(0), I4(0);
  T pos = a;

  for (unsigned int i = 0; i < bins; ++i)
  {
    pos += dr;
    I4 += func(pos);
    pos += dr;
    I2 += func(pos);
  }

  return (func(a) + 2 * I2 + 4 * I4 + func(b)) * (dr / 3);
}

#endif
