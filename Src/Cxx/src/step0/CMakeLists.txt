#
# This file is a part of TPCI_SEDRA project
# Copyright (c) INRIA 2015
#
# Contributor (s) : Maurice Bremond
# Contacts : maurice.bremond@inria.fr
# 
# This project is headed by SED Rhone-Alpes service at INRIA.
#
cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
add_library(tpsed SHARED HelloWorld.cpp)
set_target_properties(tpsed PROPERTIES SOVERSION 0)
enable_testing()
add_subdirectory(tests)
