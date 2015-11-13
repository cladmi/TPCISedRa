/* Siconos-Kernel, Copyright INRIA 2005-2012.
 * Siconos is a program dedicated to modeling, simulation and control
 * of non smooth dynamical systems.
 * Siconos is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * Siconos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Siconos; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Contact: Vincent ACARY, siconos-team@lists.gforge.inria.fr
*/

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <iostream>

#include <cstring>

CppUnit::Test* GetTest(CppUnit::Test* tests, const std::string& name);

/* get a test pointer in the test suite */

CppUnit::Test* GetTest(CppUnit::Test* tests, const std::string& name)
{

  CppUnit::TestSuite* testSuite = dynamic_cast<CppUnit::TestSuite *>(tests);

  CppUnit::Test* returnTest = NULL;

  if (testSuite)
  {
    if (testSuite->getName() == name)
    {
      return (testSuite);
    }
    else
    {
      std::vector<CppUnit::Test*> allTests = testSuite->getTests();
      std::vector<CppUnit::Test*>::iterator testi;
      for (testi = allTests.begin();
           testi != allTests.end();
           testi++)
      {
        returnTest = GetTest(*testi, name);
        if (returnTest)
          return (returnTest);
      }
    }
  }
  else
  {
    if (tests->getName() == name)
    {
      return (tests);
    }
  }
  return NULL;
}

int main(int argc, char** argv)
{

  // Registry and test suite
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  CppUnit::TestSuite *testSuite = static_cast<CppUnit::TestSuite*>(registry.makeTest());

  if (argc == 2)
  {
    // The object to run tests
    CppUnit::TextUi::TestRunner runner;

    // get the test
    CppUnit::Test * test = GetTest(testSuite, argv[1]);

    if (test != NULL)
    {
      runner.addTest(test);

      bool wasSucessful = false;

      wasSucessful = runner.run("", false, true, false);
      return wasSucessful ? 0 : 1;
    }
    else
    {
      std::cerr << "Cannot find test : " << argv[1] << std::endl;
      return 1;
    }

  }

  else
  {
    std::cerr << "Error, no test given" << std::endl;
    return 1;
  }
}
