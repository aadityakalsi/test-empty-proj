
# proj header_only sub module

set(header_only_dirname header_only)

# -- Exported headers
set(header_only_hdrs hdronly.h)

# -- Install headers
install_hdr(${header_only_hdrs})

add_hdrs_ide(${header_only_hdrs})

# -- Add tests subfolder
add_subdirectory(test)


