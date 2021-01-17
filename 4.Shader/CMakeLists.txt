cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(GLAD_H ${PROJECT_SOURCE_DIR}/../include)
set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include)
include_directories(${GLAD_H} ${GLFW_H})

set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${GLFW_LINK})

set(SOURCE1 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c shader_in_out.cpp)
add_executable(shader_in_out ${SOURCE1})

set(SOURCE2 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c shader_uniform.cpp)
add_executable(shader_uniform ${SOURCE2})

set(SOURCE3 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c shader_muti_attr.cpp)
add_executable(shader_muti_attr ${SOURCE3})

set(SOURCE4 ${PROJECT_SOURCE_DIR}/../third_libs/glad.c shader_loader_test.cpp)
add_executable(shader_loader_test ${SOURCE3})

if (APPLE)
    target_link_libraries(shader_in_out "-framework OpenGL")
    target_link_libraries(shader_uniform "-framework OpenGL")
    target_link_libraries(shader_muti_attr "-framework OpenGL")
    target_link_libraries(shader_loader_test "-framework OpenGL")
endif()

