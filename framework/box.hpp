#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
public:
  Box(){std::cout << "Box created." << std::endl;};
  Box(glm::vec3 minPoint, glm::vec3 maxPoint)
    : minPoint_(minPoint), maxPoint_(maxPoint)
    {std::cout << "Box created." << std::endl;};
  Box(glm::vec3 minPoint, glm::vec3 maxPoint, std::string name, Color color, Material material) : Shape(name, color, material) // , initialisierungsliste
  {
    minPoint_ = minPoint;
    maxPoint_ = maxPoint;
    std::cout << "Box created." << std::endl;
  }
  ~Box(){std::cout << "Box deleted." << std::endl;};

  float getSideLengthOf(float start, float end) const;
  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
  //HitPoint intersect(Ray const& ray);


private:
  glm::vec3 minPoint_{0.0f, 0.0f, 0.0f};
  glm::vec3 maxPoint_{1.0f, 1.0f, 1.0f};
};

#endif //BOX_HPP