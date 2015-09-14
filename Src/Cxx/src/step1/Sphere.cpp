#include "Sphere.hpp"

#include <math.h>

double Sphere::volume() const
{
  return 4 * M_PI * pow (this->_radius, 3.) / 3.;
}
