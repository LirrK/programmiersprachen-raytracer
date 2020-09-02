#include "box.hpp"

float Box::area() const {
  float sideA = getSideLengthOf(minPoint_.x, maxPoint_.x);
  float sideB = getSideLengthOf(minPoint_.y, maxPoint_.y);
  float sideC = getSideLengthOf(minPoint_.z, maxPoint_.z);
  return ((2*(sideA*sideB) + 2*(sideA*sideC) + 2*(sideA*sideC)));
}
float Box::volume() const {
  float sideA = getSideLengthOf(minPoint_.x, maxPoint_.x);
  float sideB = getSideLengthOf(minPoint_.y, maxPoint_.y);
  float sideC = getSideLengthOf(minPoint_.z, maxPoint_.z);
  return (sideA*sideB*sideC);
}

float Box::getSideLengthOf(float start, float end) const {
  if(start == end) { return 0; }
  else if( start < end) { return (end - start); }
  else { return (start - end); }
}

std::ostream& Box::print(std::ostream& os) const {
  Shape::print(os);
  return os << "MinPoint: [ " << minPoint_.x << " , " << minPoint_.y << " , " 
            << minPoint_.z << " ]" << std::endl << "MaxPoint: [ " << maxPoint_.x 
            << " , " << maxPoint_.y << " , " << maxPoint_.z << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Box const& s) {
  return s.print(os);
}

/*HitPoint intersect(Ray const& ray) {
  HitPoint hitpoint;
  hitpoint.distance = 0.0f;
  hitpoint.nameOfObjectHit = "empty";
  hitpoint.colorOfObjectHit
  return hitpoint;

  HitPoint hitpoint;
  Ray norm;
  norm.direction = {0.0f, 0.0f, 0.1f};
  float distance = 0.0f;

  hitpoint.nameOfObjectHit = "empty";
  hitpoint.colorOfObjectHit = {0.4f, 0.4f, 0.4f};
  hitpoint.distance = distance;
  hitpoint.hit = false;

  return hitpoint;
}
*/