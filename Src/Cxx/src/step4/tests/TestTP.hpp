#ifndef TestTP_hpp
#define TestTP_hpp

#include <cppunit/extensions/HelperMacros.h>

class TestTP : public CppUnit::TestFixture
{

private:

  CPPUNIT_TEST_SUITE(TestTP);

  CPPUNIT_TEST(testVolume);

  CPPUNIT_TEST(testIsVowel);
  CPPUNIT_TEST(testCountVowels);
  CPPUNIT_TEST(testCountConsonants);

  CPPUNIT_TEST_SUITE_END();

  std::stringstream _buffer;

  void testVolume();

  void testIsVowel();
  void testCountVowels();
  void testCountConsonants();

  std::string ascii_table;

public:
  void setUp();
  void tearDown();

};

#endif




