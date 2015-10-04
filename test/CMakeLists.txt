# TEST: sub module

# TEST: proj header_only sub module

add_test_exe    (test_hdronly test_hdronly.c)
test_link_libs  (test_hdronly )
create_test     (test_hdronly)

# TEST: proj test_lib sub module

add_test_exe    (test_test_lib test_test_lib.c)
test_link_libs  (test_test_lib test_lib)
create_test     (test_test_lib)

# TEST: proj test_exec sub module

add_test_exe    (test_test_exec test_test_exec.c)
add_dependencies(test_test_exec test_exec)
test_link_libs  (test_test_exec )
create_test     (test_test_exec)

# TEST: proj test_lib sub module; Static library
add_definitions(-DTEST_LIB_LINK_STATIC)
add_test_exe    (test_test_lib_s test_test_lib.c)
test_link_libs  (test_test_lib_s test_lib_s)
create_test     (test_test_lib_s)
