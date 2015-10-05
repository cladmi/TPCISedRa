/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * Contributor (s) : Maurice Bremond
 * Contacts : maurice.bremond@inria.fr
 * 
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
#include "Sphere.hpp"

#include <math.h>

static  double a = (4 * M_PI /3.);


double Sphere::volume() const
{
  return 4 * M_PI * pow(this->_radius, 3)/3;
}
