/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
#include "Sphere.hpp"

double Sphere::volume() const
{
  return Sphere::four_thirds_of_pi * pow (this->_radius, 3.);
}
