
# proj test_exec sub module

set(test_exec_dirname test_exec)

# -- Exported headers
set(test_exec_hdrs )

# -- Install headers
install_hdr(${test_exec_hdrs})
add_hdrs_ide(${test_exec_hdrs})

# -- Add executables
add_exe(test_exe test_exe.c)
link_libs(test_exe )
set_tgt_ver(test_exe 1)
install_tgt(test_exe)

# -- Add tests subfolder
add_subdirectory(test)


