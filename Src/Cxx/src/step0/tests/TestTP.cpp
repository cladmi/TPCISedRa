#include "TestTP.hpp"
#include "HelloWorld.hpp"

#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestTP);

void TestTP::setUp()
{}

void TestTP::tearDown()
{}

void TestTP::testPrint()
{
  std::cout.rdbuf(_buffer.rdbuf());

  HelloWorld hello_world;
  hello_world.print();

  CPPUNIT_ASSERT(_buffer.str() == "Hello World!\n");
}
