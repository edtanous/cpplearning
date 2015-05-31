
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

ADD_SUBDIRECTORY( subdir )
MACRO_ADD_SOURCES( foo.cpp )
