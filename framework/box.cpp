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