cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(OPENGL_H ${PROJECT_SOURCE_DIR}/../include)
include_directories(${OPENGL_H})

set(SOURCE glm_demo.cpp)
add_executable(glm_demo ${SOURCE})


