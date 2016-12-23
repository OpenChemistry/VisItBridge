#  Try to find BoxLib library and headers.
#  This file sets the following variables:
#
#  BoxLib_INCLUDE_DIR, where to find BoxLib.H, etc.
#  BoxLib_LIBRARIES, the libraries to link against
#  BoxLib_FOUND, If false, do not try to use BoxLib.
#
# Also defined, but not for general use are:
#  BoxLib_LIBRARY, the full path to the BoxLib library.
#  BoxLib_INCLUDE_PATH, for CMake backward compatibility

FIND_PATH( BoxLib_INCLUDE_DIR BoxLib.H
  /usr/local/include
  /usr/include
)

FIND_LIBRARY( BoxLib_LIBRARY NAMES cboxlib
  /usr/lib
  /usr/local/lib
)

SET( BoxLib_FOUND "NO" )
IF(BoxLib_INCLUDE_DIR)
  IF(BoxLib_LIBRARY)

    SET( BoxLib_LIBRARIES ${BoxLib_LIBRARY})
    SET( BoxLib_FOUND "YES" )

    #The following deprecated settings are for backwards compatibility with CMake1.4
    SET (BoxLib_INCLUDE_PATH ${BoxLib_INCLUDE_DIR})

  ELSE()
    IF(BoxLib_FIND_REQUIRED)
      message(SEND_ERROR "Unable to find the requested BoxLib libraries.")
    ENDIF()
  ENDIF()
ENDIF()

# handle the QUIETLY and REQUIRED arguments and set BoxLib_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BoxLib DEFAULT_MSG BoxLib_LIBRARY BoxLib_INCLUDE_DIR)

MARK_AS_ADVANCED(
  BoxLib_INCLUDE_DIR
  BoxLib_LIBRARY
  BoxLib_DIR
)
