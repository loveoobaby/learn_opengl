cmake_minimum_required(VERSION 3.0.0)
project(camera VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
include_directories(${GLAD_H})


set(SOURCE1 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c camera.cpp)
add_executable(camera ${SOURCE1})

set(SOURCE2 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c camera_keyboard.cpp)
add_executable(camera_keyboard ${SOURCE2})

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(camera ${OPENGL_gl_LIBRARY})
target_link_libraries(camera_keyboard ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(camera ${GLFW_LIBRARIES})
target_link_libraries(camera_keyboard ${GLFW_LIBRARIES})
