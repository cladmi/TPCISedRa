#ifndef TestTP_hpp
#define TestTP_hpp

#include <cppunit/extensions/HelperMacros.h>

class TestTP : public CppUnit::TestFixture
{

private:

  CPPUNIT_TEST_SUITE(TestTP);

  CPPUNIT_TEST(testVolume);

  CPPUNIT_TEST_SUITE_END();

  std::stringstream _buffer;

  void testVolume();

public:
  void setUp();
  void tearDown();

};

#endif




