#include "sphere.hpp"

float Sphere::area() const {
  return (4*(pow(radius_, 2))*M_PI);
}

float Sphere::volume() const {
  return ((4.0f/3.0f)*(pow(radius_, 3))*M_PI);
}
