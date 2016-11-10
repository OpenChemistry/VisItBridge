#  Try to find GFortran libraries.
#  This file sets the following variables:
#
#  GFORTRAN_LIBRARIES, the libraries to link against
#  GFORTRAN_FOUND, If false, do not try to use GFORTRAN

find_library(gfortran_LIBRARY NAMES gfortran
  PATHS
  /usr/lib
  /usr/local/lib
  PATH_SUFFIXES
  gcc/x86_64-linux-gnu/5/
  )
if (gfortran_LIBRARY)
  set(GFortran_LIBRARIES ${gfortran_LIBRARY})
endif()
find_library(quadmath_LIBRARY NAMES quadmath
  PATHS
  /usr/lib
  /usr/local/lib
  PATH_SUFFIXES
  gcc/x86_64-linux-gnu/5/
  )
if (quadmath_LIBRARY)
  list(APPEND GFortran_LIBRARIES ${quadmath_LIBRARY})
endif()

# handle the QUIETLY and REQUIRED arguments and set GFortran_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GFortran DEFAULT_MSG gfortran_LIBRARY quadmath_LIBRARY)

MARK_AS_ADVANCED(
  gfortran_LIBRARY
  quadmath_LIBRARY
)
