#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>
#include "color.hpp"

struct Material {
  // *Empty constructor*
  Material(){};
  // *constructor with initalization list*
  Material(std::string name, Color const& ka, Color const& kd,
          Color const& ks, float m)
          : name(name), ka(ka), kd(kd), ks(ks), m(m)
          {};

  // *member variables*
  std::string name;
  Color ka = {0.5f, 0.5f, 0.5f}; // Koeffizient ambiente Reflexion
  Color kd = {0.5f, 0.5f, 0.5f}; // Koeffizient diffuse Reflexion
  Color ks = {0.5f, 0.5f, 0.5f}; // Koeffizient spiegelnde Reflexion
  float m = 0.0f; // Exponent für spiegelnde Reflexion
};

#endif //MATERIAL_HPP