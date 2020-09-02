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
  Sphere(){std::cout << "Sphere created." << std::endl;};
  Sphere(glm::vec3 center, float radius)
    : center_(center), radius_(radius)
    {std::cout << "Sphere created." << std::endl;};
  Sphere(glm::vec3 center, float radius, std::string name, Color color, Material material) : Shape(name, color, material)
  {
    center_ = center;
    radius_ = radius;
    std::cout << "Sphere created." << std::endl;
  }
  ~Sphere() {std::cout << "Sphere deleted." << std::endl;};

  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
  HitPoint intersect(Ray const& ray);

private:
  glm::vec3 center_{0.0f, 0.0f, 0.0f};
  float radius_ = 1.0f;

};

#endif //SPHERE_HPP