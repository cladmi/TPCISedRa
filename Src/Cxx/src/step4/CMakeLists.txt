cmake_minimum_required(VERSION 2.8)
project(TP CXX)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
add_library(tpsed SHARED Alphabet.cpp Sphere.cpp)
set_target_properties(tpsed PROPERTIES SOVERSION 3)

include(TestCXXAcceptsFlag)
macro(add_cxx_compiler_flag _flag)
  string(REPLACE "-" "_" _flag_var ${_flag})
  check_cxx_accepts_flag("${_flag}" CXX_COMPILER_${_flag_var}_OK)
  if(CXX_COMPILER_${_flag_var}_OK)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_flag}")
  endif()
endmacro()
add_cxx_compiler_flag(-fprofile-arcs)
add_cxx_compiler_flag(-ftest-coverage)

enable_testing()
add_subdirectory(tests)


