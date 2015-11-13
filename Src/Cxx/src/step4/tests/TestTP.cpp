#include "TestTP.hpp"
#include "Sphere.hpp"
#include "Alphabet.hpp"

#include <math.h>

CPPUNIT_TEST_SUITE_REGISTRATION(TestTP);

void TestTP::setUp()
{
  this->ascii_table.resize(255);
  for(unsigned char c=0; c<255; ++c)
  {
    ascii_table[c]=c;
  }
}

void TestTP::tearDown()
{}

void TestTP::testVolume()
{
  Sphere sphere(1.5);

  CPPUNIT_ASSERT(
    fabs(14.137166941154069 - sphere.volume()) < sqrt(DBL_EPSILON));

}

void TestTP::testIsVowel()
{
  std::string vowels = "aeiouyAEIOUY";

  for(unsigned char c=0; c<255; ++c)
  {

    if(vowels.find(c) == std::string::npos)
    {
      CPPUNIT_ASSERT(!Alphabet::IsVowel(c));
    }
    else
    {
      CPPUNIT_ASSERT(Alphabet::IsVowel(c));
    }
  }

}

void TestTP::testCountVowels()
{
  CPPUNIT_ASSERT(Alphabet::CountVowels(ascii_table) == 12);
}

void TestTP::testCountConsonants()
{
  CPPUNIT_ASSERT(Alphabet::CountConsonants(ascii_table) == 40);
}
