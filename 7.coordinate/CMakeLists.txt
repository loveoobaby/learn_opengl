cmake_minimum_required(VERSION 3.0.0)
project(coordinate VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
include_directories(${GLAD_H})

set(SOURCE ${PROJECT_SOURCE_DIR}/../third_libs/glad.c texture_muti_demo.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})

