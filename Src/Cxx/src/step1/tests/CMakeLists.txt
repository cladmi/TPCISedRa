#
# This file is a part of TPCI_SEDRA project
# Copyright (c) INRIA 2015
#
# This project is headed by SED Rhone-Alpes service at INRIA.
#
enable_testing()
find_library(cppunit cppunit)
include_directories(${CMAKE_SOURCE_DIR})
link_directories(${CMAKE_BUILD_DIR})
add_executable(tptest testMain.cpp TestTP.cpp)
target_link_libraries(tptest cppunit tpsed)
add_test(TestVolume tptest TestTP::testVolume)
