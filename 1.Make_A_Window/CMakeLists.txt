cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include)
include_directories(${GLAD_H} ${GLFW_H})

set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${GLFW_LINK})

include(CTest)
enable_testing()

set(SOURCE ${PROJECT_SOURCE_DIR}/../third_libs/glad.c main.cpp)
add_executable(learnopengl ${SOURCE})

if (APPLE)
    target_link_libraries(learnopengl "-framework OpenGL")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
