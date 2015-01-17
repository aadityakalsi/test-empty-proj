
# TEST: proj test_exec sub module

add_test_exe    (test_test_exec test_test_exec.c)
add_dependencies(test_test_exec test_exec)
test_link_libs  (test_test_exec )
create_test     (test_test_exec)


