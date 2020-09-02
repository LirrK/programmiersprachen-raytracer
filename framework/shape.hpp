#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <math.h>
#include <string>
#include "color.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"
#include "material.hpp"

class Shape
{
public:
  Shape(){std::cout << "Shape created." << std::endl;};
  Shape(std::string name, Color color, Material material)
    : name_(name), color_(color), material_(material)
    {std::cout << "Shape created." << std::endl;};
  ~Shape(){std::cout << "Shape deleted." << std::endl;};

  virtual float area() const = 0;
  virtual float volume() const = 0;
  virtual std::ostream& print(std::ostream& os) const;
  //virtual HitPoint intersect(Ray const& ray) = 0;

protected:
  std::string name_;
  Color color_{0.5f, 0.5f, 0.5f};
  Material material_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);


#endif //SHAPE_HPP