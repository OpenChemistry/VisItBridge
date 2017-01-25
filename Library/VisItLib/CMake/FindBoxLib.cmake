#  Try to find BoxLib library and headers.
#  This file sets the following variables:
#
#  BoxLib_INCLUDE_DIR, where to find BoxLib.H, etc.
#  BoxLib_LIBRARIES, the libraries to link against
#  BoxLib_FOUND, If false, do not try to use BoxLib.

FIND_PATH( BoxLib_INCLUDE_DIR BoxLib.H
  /usr/local/include
  /usr/include
)

FIND_LIBRARY( BoxLib_C_LIBRARY NAMES cboxlib
  /usr/lib
  /usr/local/lib
)

FIND_LIBRARY( BoxLib_Fortran_LIBRARY NAMES fboxlib
  /usr/lib
  /usr/local/lib
)

IF(BoxLib_C_LIBRARY AND BoxLib_Fortran_LIBRARY)
  SET( BoxLib_LIBRARIES ${BoxLib_C_LIBRARY} ${BoxLib_Fortran_LIBRARY})
ENDIF()

# handle the QUIETLY and REQUIRED arguments and set BoxLib_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BoxLib DEFAULT_MSG BoxLib_C_LIBRARY BoxLib_Fortran_LIBRARY BoxLib_INCLUDE_DIR)

MARK_AS_ADVANCED(
  BoxLib_INCLUDE_DIR
  BoxLib_C_LIBRARY
  BoxLib_Fortran_LIBRARY
)
