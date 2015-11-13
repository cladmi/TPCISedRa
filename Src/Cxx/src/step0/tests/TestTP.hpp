/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
#ifndef TestTP_hpp
#define TestTP_hpp

#include <cppunit/extensions/HelperMacros.h>

class TestTP : public CppUnit::TestFixture
{

private:

  CPPUNIT_TEST_SUITE(TestTP);

  CPPUNIT_TEST(testPrint);

  CPPUNIT_TEST_SUITE_END();

  void testPrint();

  std::stringstream _buffer;

public:
  void setUp();
  void tearDown();

};

#endif




