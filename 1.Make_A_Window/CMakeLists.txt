cmake_minimum_required(VERSION 3.0.0)
project(make_a_window VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
include_directories(${GLAD_H})

set(SOURCE ${PROJECT_SOURCE_DIR}/../third_libs/glad.c main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

set(SOURCE2 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c make_a_window2.cpp)
add_executable(make_a_window2 ${SOURCE2})

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(make_a_window2 ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(make_a_window2 ${GLFW_LIBRARIES})
