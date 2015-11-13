#include "Sphere.hpp"

#include <math.h>

static double _4_pi_on_3 = 4. * M_PI / 3.;

double Sphere::volume() const
{
  return _4_pi_on_3 * pow (this->_radius, 3.);
}
