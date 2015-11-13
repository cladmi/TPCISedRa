/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
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
