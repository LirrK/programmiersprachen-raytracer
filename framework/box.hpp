#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
public:
  Box(){};
  Box(glm::vec3 minPoint, glm::vec3 maxPoint)
    : minPoint_(minPoint), maxPoint_(maxPoint){};
  Box(glm::vec3 minPoint, glm::vec3 maxPoint, std::string name, Color color) : Shape(name, color)
  {
    minPoint_ = minPoint;
    maxPoint_ = maxPoint;
  }

  float getSideLengthOf(float start, float end) const;
  float area() const override;
  float volume() const override;

private:
  glm::vec3 minPoint_{0.0f, 0.0f, 0.0f};
  glm::vec3 maxPoint_{1.0f, 1.0f, 1.0f};
};

#endif //BOX_HPP