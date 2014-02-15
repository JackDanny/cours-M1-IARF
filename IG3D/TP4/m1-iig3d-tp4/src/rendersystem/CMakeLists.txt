
find_package(Qt4 REQUIRED) # find and setup Qt4 for this project
find_package(OpenGL REQUIRED)

# the variable "qtproject_SRCS" contains all .cpp files of this project
FILE(GLOB folder_source *.cpp)
FILE(GLOB folder_header *.h)
FILE(GLOB shaders  ../../shaders/*.glsl)
SOURCE_GROUP("Source Files" FILES ${folder_source})
SOURCE_GROUP("Header Files" FILES ${folder_header})

# moc files
set(renderer_MOC_HDRS
mainwindow.h
openglwidget.h
)

SET( HEADER_PATH ./ )

include_directories(
   ${HEADER_PATH}
   ${CMAKE_SOURCE_DIR}/src
   ${CMAKE_SOURCE_DIR}/src/fileloaders
)

QT4_WRAP_CPP(renderer_MOC_HDRS ${renderer_MOC_HDRS})

# tell cmake to create .moc files for all files in the variable qtproject_SRCS that require such a file.
# note: this assumes that you use #include "header.moc" in your files
#qt4_automoc(${openglrenderer_SRCS})

# the next line sets up include and link directories and defines some variables that we will use.
# you can modify the behavior by setting some variables, e.g.

set(QT_USE_OPENGL TRUE)

# -> this will cause cmake to include and link against the OpenGL module
include(${QT_USE_FILE})

include_directories(
   ${QT_INCLUDE_DIR}
   ${QT_QTGUI_INCLUDE_DIR}
   ${QT_QTOPENGL_INCLUDE_DIR}
)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

if (APPLE)
#Compile for MacOsX system
add_executable(minimalRenderer ${folder_source} ${folder_header}  ${renderer_MOC_HDRS} core_profile_attributes.mm)
target_link_libraries(minimalRenderer ${QT_LIBRARIES} ${QT_QTGUI_LIBRARIES} ${QT_QTOPENGL_LIBRARIES} ${OPENGL_LIBRARIES} "-framework Foundation" "-framework Cocoa" m -L${LIB_INSTALL_DIR} fileloaders )
else()
#build on Linux
add_executable(minimalrenderer ${folder_source} ${folder_header}  ${renderer_MOC_HDRS} ${shaders})
target_link_libraries(minimalrenderer ${QT_LIBRARIES} ${QT_QTGUI_LIBRARIES} ${QT_QTOPENGL_LIBRARIES} ${OPENGL_LIBRARIES}  fileloaders)
endif()
