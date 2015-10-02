#include "TestTP.hpp"
#include "Sphere.hpp"

#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestTP);

void TestTP::setUp()
{}

void TestTP::tearDown()
{}

void TestTP::testVolume()
{
  Sphere sphere(1.5);

  CPPUNIT_ASSERT(14.137166941154069 == sphere.volume());

}
