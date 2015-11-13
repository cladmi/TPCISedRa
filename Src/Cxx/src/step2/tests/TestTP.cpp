/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
#include "TestTP.hpp"
#include "Sphere.hpp"
#include <math.h>

CPPUNIT_TEST_SUITE_REGISTRATION(TestTP);

void TestTP::setUp()
{}

void TestTP::tearDown()
{}

void TestTP::testVolume()
{
  Sphere sphere(1.5);

  //  CPPUNIT_ASSERT(14.137166941154069 == sphere.volume());
  CPPUNIT_ASSERT(fabs(14.137166941154069 - sphere.volume()) < sqrt(DBL_EPSILON));


}
