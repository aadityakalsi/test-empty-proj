# Generated CMakeLists.txt for install test test_unittest
set_directory_properties(PROPERTIES INCLUDE_DIRECTORIES /home/akalsi/code/test-empty-proj/install/include)
if (USE_CODE_COV)
  add_definitions(-O0 -fprofile-arcs -ftest-coverage)
  set(CMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")
  file(MAKE_DIRECTORY /home/akalsi/code/test-empty-proj/build/coverage)
endif()
add_executable(test_unittest_install;test_unittest.c /home/akalsi/code/test-empty-proj/unittest/unittest.h)
add_dependencies(test_unittest_install install_for_check_done)
set_directory_properties(PROPERTIES LINK_DIRECTORIES /home/akalsi/code/test-empty-proj/install/lib)
link_libs_install(test_unittest_install)
add_custom_command(OUTPUT test_unittest.toi.done
  COMMAND test_unittest_install 
  COMMAND "/usr/bin/cmake" -E touch test_unittest.toi.done
  DEPENDS test_unittest_install)
add_custom_target(test_unittest_install_run DEPENDS test_unittest.toi.done)
add_dependencies(check_on_install test_unittest_install_run)
