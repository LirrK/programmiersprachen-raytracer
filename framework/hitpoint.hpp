#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

struct HitPoint
{
  bool hit = false;
  float distance;
  std::string nameOfObjectHit;
  Color colorOfObjectHit;
  glm::vec3 locationOfHit;
  glm::vec3 directionOfHit;
};


#endif //HITPOINT_HPP