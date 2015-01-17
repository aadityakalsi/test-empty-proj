
# TEST: proj header_only sub module

add_test_exe    (test_hdronly test_hdronly.c)
test_link_libs  (test_hdronly )
create_test     (test_hdronly)


