#
# This file is a part of TPCI_SEDRA project
# Copyright (c) INRIA 2015
#
# This project is headed by SED Rhone-Alpes service at INRIA.
#
cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-Wfloat-equal CXX_WFLOAT_EQUAL)
if(CXX_WFLOAT_EQUAL)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal")
endif()
add_library(tpsed SHARED Sphere.cpp)
add_executable(bench bench.cpp)
target_link_libraries(bench tpsed;rt) # note: rt is needed only for
                                      # glibc versions before 2.17
set_target_properties(tpsed PROPERTIES SOVERSION 1)
enable_testing()
add_subdirectory(tests)
