#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <math.h>

class Shape
{
public:
  virtual float area() const = 0;
  virtual float volume() const = 0;
};

#endif //SHAPE_HPP