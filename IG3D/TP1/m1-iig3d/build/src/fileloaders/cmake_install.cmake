# Install script for directory: /home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/src/fileloaders

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

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1.0"
      "$ENV{DESTDIR}/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1"
      "$ENV{DESTDIR}/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1.0;/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1;/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so")
FILE(INSTALL DESTINATION "/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib" TYPE SHARED_LIBRARY FILES
    "/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1.0"
    "/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1"
    "/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1.0"
      "$ENV{DESTDIR}/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so.0.1"
      "$ENV{DESTDIR}/home/jackdanny/Bureau/M1_IARF/cours-M1-IARF/IG3D/TP1/m1-iig3d/lib/libfileloaders.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

