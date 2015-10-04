# project

cmake_minimum_required(VERSION 3.0)

set(CPACK_PACKAGE_VERSION "0.1.1")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_PACKAGE_CONTACT )

set(PROJ_LICENSE_FILE COPYING)
set(PROJ_README_FILE  README.txt)

# -- Include the tests in the bin folder?
set(INCLUDE_TEST_IN_BIN FALSE)

# -- Set project name
project(test-empty-proj C CXX)

# -- Include the magic ProjTools
include("cmake/ProjTools.cmake")

# -- Add the subdirectories
set(PROJ_SUBDIRS unittest; doc; tools; test)

# add all subdirs
foreach(subdir ${PROJ_SUBDIRS})
  add_subdirectory(${subdir})
endforeach(subdir)

# ---
# Project sub parts
# ---

# HEADER_ONLY
# -- Exported headers
set(header_only_hdrs include/header_only/hdronly.h)

# -- Install headers
install_hdr(${header_only_hdrs})

# TEST_EXEC
# -- Exported headers
set(test_exec_hdrs )

# -- Install headers
install_hdr(${test_exec_hdrs})

# -- Add executables
add_exe(test_exec src/test_exec/test_exe.c)
link_libs(test_exec )
set_tgt_ver(test_exec 1)
install_tgt(test_exec)

# TEST_LIB
set(test_lib_xprt_hdr include/test_lib/api.h)

add_lib(test_lib SHARED src/test_lib/test_lib.c)
add_lib_build_def(test_lib include/test_lib/export.h TEST_LIB)
link_libs(test_lib )
set_tgt_ver(test_lib 0.1.1 0.1)

add_lib(test_lib_s STATIC src/test_lib/test_lib.c)
add_lib_build_def(test_lib_s include/test_lib/export.h TEST_LIB)
link_libs(test_lib_s )
set_tgt_ver(test_lib_s 0.1.1 0.1)

install_hdr(${test_lib_xprt_hdr})
install_tgt(test_lib)
install_tgt(test_lib_s)
