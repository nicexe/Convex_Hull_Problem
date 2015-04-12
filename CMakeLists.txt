cmake_minimum_required(VERSION 3.1)
project(Convex_Hull_Problem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(Convex_Hull_Problem ${SOURCE_FILES} menu.h menu.cpp visualOutput.h visualOutput.cpp grahamScan.h grahamScan.cpp giftWrapping.h giftWrapping.cpp divideAndConquer.h divideAndConquer.cpp)
target_link_libraries(Convex_Hull_Problem ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})