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
#ifndef Sphere_hpp
#define Sphere_hpp

#include <math.h>

class Sphere
{
public:
  Sphere(const double& radius) : _radius(radius) {};

  double volume () const;

private:
  static const double four_thirds_of_pi = 4. * M_PI / 3.;
  double _radius;
};
#endif
