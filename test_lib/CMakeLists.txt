
# proj test_lib sub module

set(test_lib_dirname test_lib)

# -- Exported headers
set(test_lib_hdrs export.h)

# -- Install headers
install_hdr(${test_lib_hdrs})
add_hdrs_ide(${test_lib_hdrs})

add_lib(test_lib SHARED test_lib.c export.h)
add_lib_build_def(test_lib TEST_LIB_BUILD)
link_libs(test_lib )
set_tgt_ver(test_lib 0.1.1 0.1)
install_tgt(test_lib)

# -- Add tests subfolder
add_subdirectory(test)


