enable_testing()
find_library(cppunit cppunit)
find_library(gcov gcov)
include_directories(${CMAKE_SOURCE_DIR})
link_directories(${CMAKE_BUILD_DIR})
add_executable(tptest testMain.cpp TestTP.cpp)

find_program(GCOVR gcovr)
find_program(LCOV lcov)
find_program(GENHTML genhtml )

target_link_libraries(tptest cppunit tpsed gcov)

add_custom_target(check 
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target test)
add_custom_target(coverage) 
function(new_test exec arg)
  string(REPLACE ":" "_" _tname ${arg})
  add_test(${_tname} ${exec} ${arg})
  add_custom_target(${_tname}.xml
    COMMAND ${LCOV} --directory . --capture --output-file ${_tname}.info
    COMMAND ${GENHTML} -o ${_tname} ${_tname}.info
    COMMAND ${GCOVR} -x -r ${CMAKE_SOURCE_DIR} -e ${CMAKE_SOURCE_DIR}/tests -o ${_tname}.xml
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  add_dependencies(${_tname}.xml check)
  add_dependencies(coverage check ${_tname}.xml)
endfunction()

new_test(tptest TestTP::testVolume)
new_test(tptest TestTP::testIsVowel)
new_test(tptest TestTP::testCountVowels)
new_test(tptest TestTP::testCountConsonants)
