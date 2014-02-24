SET( LIBRARY_VERSION "0.1.0" )
SET( LIBRARY_SOVERSION "0.1" )

SET( HEADER_PATH ./ )
FILE(GLOB folder_source *.cpp)
FILE(GLOB folder_header ${HEADER_PATH}/*.h)

SOURCE_GROUP("Source Files" FILES ${folder_source})
SOURCE_GROUP("Header Files" FILES ${folder_header})

#find_package(OpenGL REQUIRED)
find_package(Qt4 REQUIRED) # find and setup Qt4 for this project
set(QT_USE_OPENGL TRUE)
include(${QT_USE_FILE})

include_directories(
   ${QT_INCLUDE_DIR}
)

include_directories(
   ${HEADER_PATH}/
   ${CMAKE_SOURCE_DIR}/src
)

#set(LIBS ${QT_LIBRARIES} ${QT_QTGUI_LIBRARIES} ${QT_QTOPENGL_LIBRARIES} ${OPENGL_LIBRARIES})
set(LIBS ${QT_LIBRARIES})

ADD_LIBRARY( fileloaders SHARED
        ${folder_source}
        ${folder_header}
)

SET_TARGET_PROPERTIES( fileloaders PROPERTIES
        VERSION ${LIBRARY_VERSION}
        SOVERSION ${LIBRARY_SOVERSION}
)

TARGET_LINK_LIBRARIES( fileloaders  ${LIBS} )

INSTALL( TARGETS fileloaders DESTINATION ${LIB_INSTALL_DIR} )
