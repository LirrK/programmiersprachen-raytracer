#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <math.h>
#include <string>
#include "color.hpp"

class Shape
{
public:
  Shape(){};
  Shape(std::string name, Color color)
    : name_(name), color_(color) {};

  virtual float area() const = 0;
  virtual float volume() const = 0;

protected:
  std::string name_;
  Color color_{0.5f, 0.5f, 0.5f};
};

#endif //SHAPE_HPP