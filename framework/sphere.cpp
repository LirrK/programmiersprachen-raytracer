#include "sphere.hpp"

float Sphere::area() const {
  return (4*(pow(radius_, 2))*M_PI);
}

float Sphere::volume() const {
  return ((4.0f/3.0f)*(pow(radius_, 3))*M_PI);
}

std::ostream& Sphere::print(std::ostream& os) const {
  Shape::print(os);
  return os << "Center: [ " << center_.x << " , " << center_.y << " , "
            << center_.z << " ]" << std::endl << "Radius: " << radius_
            << std::endl;
}

std::ostream& operator<<(std::ostream& os, Sphere const& s) {
  return s.print(os);
}

HitPoint Sphere::intersect(Ray const& ray) {
  HitPoint hitpoint;
  Ray norm;
  norm.direction = glm::normalize(ray.direction);
  float distance = 0.0f;

  hitpoint.hit = glm::intersectRaySphere(ray.origin, norm.direction, center_, radius_ * radius_, distance);
  hitpoint.nameOfObjectHit = name_;
  hitpoint.colorOfObjectHit = color_;
  hitpoint.distance = distance;

  return hitpoint;
}