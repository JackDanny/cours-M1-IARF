project(minimalRenderer)

cmake_minimum_required(VERSION 2.6)

# some general cmake def
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -ansi -fPIC")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_DEBUG}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -mfpmath=sse -finline")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -DQT_NO_DEBUG -DQT_NO_CHECK -mmmx -msse -msse2 -msse3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE}") 

if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib-debug)
set(LIB_INSTALL_DIR ${CMAKE_SOURCE_DIR}/lib-debug)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin-dbg)
else()
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(LIB_INSTALL_DIR ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

# tell cmake to process CMakeLists.cmake in that subdirectory
add_subdirectory(src)
