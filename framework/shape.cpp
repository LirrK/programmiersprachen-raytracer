#include "shape.hpp"

std::ostream& Shape::print(std::ostream& os) const {
  return  std::cout << "Name: " << name_ << std::endl
                    << "RGB Farbcode: [ " << color_.r << " , " << color_.g
                    << " , " << color_.b << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
  return s.print(os);
}