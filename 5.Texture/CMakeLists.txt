cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include)
include_directories(${GLAD_H} ${GLFW_H})

set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${GLFW_LINK})

set(SOURCE1 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c texture.cpp)
add_executable(texture_demo ${SOURCE1})

if (APPLE)
    target_link_libraries(texture_demo "-framework OpenGL")
endif()

