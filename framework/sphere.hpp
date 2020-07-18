#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"

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

  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
  //HitPoint& intersect(Ray const& ray);
  // warum muss der nicht nochmal in der hpp auftauchen? warum funktioniert das so?
  // std::ostream& operator<<(std::ostream& os, Sphere const& s) override;

private:
  glm::vec3 center_{0.0f, 0.0f, 0.0f};
  float radius_ = 1.0f;

};

#endif //SPHERE_HPP