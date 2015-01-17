
# TEST: proj test_lib sub module

add_test_exe    (test_test_lib test_test_lib.c)
test_link_libs  (test_test_lib test_lib)
create_test     (test_test_lib)


