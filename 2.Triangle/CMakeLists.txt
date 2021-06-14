cmake_minimum_required(VERSION 3.0.0)
project(trangle VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
include_directories(${GLAD_H})

set(SOURCE ${PROJECT_SOURCE_DIR}/../third_libs/glad.c main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

set(SOURCE ${PROJECT_SOURCE_DIR}/../third_libs/glad.c ${PROJECT_SOURCE_DIR}/../include/shader.cpp Trangle2.cpp)
add_executable(Trangle2 ${SOURCE})

set(SOURCE ${PROJECT_SOURCE_DIR}/../third_libs/glad.c ${PROJECT_SOURCE_DIR}/../include/shader.cpp Trangle3.cpp)
add_executable(Trangle3 ${SOURCE})

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
target_link_libraries(Trangle2 ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(Trangle2 ${GLFW_LIBRARIES})

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(Trangle3 ${OPENGL_gl_LIBRARY})

#GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(Trangle3 ${GLFW_LIBRARIES})
