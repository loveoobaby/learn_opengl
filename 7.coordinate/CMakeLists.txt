cmake_minimum_required(VERSION 3.0.0)
project(coordinate VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
include_directories(${GLAD_H})

set(SOURCE1 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c texture_muti_demo.cpp)
add_executable(coordinate ${SOURCE1})

set(SOURCE2 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c cube1.cpp)
add_executable(cube1 ${SOURCE2})

set(SOURCE3 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c cube2.cpp)
add_executable(cube2 ${SOURCE3})

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(coordinate ${OPENGL_gl_LIBRARY})
target_link_libraries(cube1 ${OPENGL_gl_LIBRARY})
target_link_libraries(cube2 ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(coordinate ${GLFW_LIBRARIES})
target_link_libraries(cube1 ${GLFW_LIBRARIES})
target_link_libraries(cube2 ${GLFW_LIBRARIES})
