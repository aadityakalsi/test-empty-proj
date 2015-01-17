
# proj test_lib sub module

set(test_lib_dirname test_lib)

# -- Exported headers
set(test_lib_hdrs )

# -- Install headers
install_hdr(${test_lib_hdrs})

add_hdrs_ide(${test_lib_hdrs})

# -- Add tests subfolder
add_subdirectory(test)


