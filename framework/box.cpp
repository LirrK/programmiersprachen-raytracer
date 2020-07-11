#include "box.hpp"

float Box::getSideLengthOf(float start, float end) const {
  if(start == end) { return 0; }
  else if( start < end) { return (end - start); }
  else { return (start - end); }
}