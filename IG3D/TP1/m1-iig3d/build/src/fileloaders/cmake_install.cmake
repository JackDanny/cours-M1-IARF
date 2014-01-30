# Install script for directory: /Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/src/fileloaders

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.0.1.0.dylib;/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.0.1.dylib;/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.dylib")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib" TYPE SHARED_LIBRARY FILES
    "/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.0.1.0.dylib"
    "/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.0.1.dylib"
    "/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.dylib"
    )
  FOREACH(file
      "$ENV{DESTDIR}/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.0.1.0.dylib"
      "$ENV{DESTDIR}/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.0.1.dylib"
      "$ENV{DESTDIR}/Users/Wedge/Desktop/M1 IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.dylib"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libfileloaders.0.1.dylib"
        "${file}")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Applications/Canopy.app/appdata/canopy-1.2.0.1610.macosx-x86_64/Canopy.app/Contents/lib"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

