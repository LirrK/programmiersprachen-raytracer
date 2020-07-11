#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"


class Sphere : public Shape
{
public:
  Sphere(){};
  Sphere(glm::vec3 center, float radius)
    : center_(center), radius_(radius){};
  Sphere(glm::vec3 center, float radius, std::string name, Color color) : Shape(name, color)
  {
    center_ = center;
    radius_ = radius;
  }

  /* Warum müssen die Methoden in sphere.hpp und nicht
     sphere.cpp definiert werden? */
  //float area() const override;
  //float volume() const override;

  float area() const override {
    return (4*(pow(radius_, 2))*M_PI);
  }

  float volume() const override {
    return ((4.0f/3.0f)*(pow(radius_, 3))*M_PI);
  }

private:
  glm::vec3 center_{0.0f, 0.0f, 0.0f};
  float radius_ = 1.0f;

};

#endif //SPHERE_HPP