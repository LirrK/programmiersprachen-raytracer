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

  float area() const override;
  float volume() const override;
  virtual std::ostream& print(std::ostream& os) const;
  // warum muss der nicht nochmal in der hpp auftauchen? warum funktioniert das so?
  //virtual std::ostream& operator<<(std::ostream& os, Sphere const& s) override;

private:
  glm::vec3 center_{0.0f, 0.0f, 0.0f};
  float radius_ = 1.0f;

};

#endif //SPHERE_HPP