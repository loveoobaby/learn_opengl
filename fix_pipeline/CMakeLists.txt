cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE glut_starter.cpp)
add_executable(glut_starter ${SOURCE})
add_executable(solar_system solar_system.cpp)
add_executable(solar_system2 solar2.cpp)
add_executable(solar_system3 solar_system3.cpp)
add_executable(sphere sphere.cpp)

if (APPLE)
    target_link_libraries(glut_starter "-framework OpenGL -framework GLUT")
    target_link_libraries(solar_system "-framework OpenGL -framework GLUT")
    target_link_libraries(solar_system2 "-framework OpenGL -framework GLUT")
    target_link_libraries(solar_system3 "-framework OpenGL -framework GLUT")
    target_link_libraries(sphere "-framework OpenGL -framework GLUT")
endif()