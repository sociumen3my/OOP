cmake_minimum_required(VERSION 3.16)
project(seminar5 LANGUAGES CXX)

add_library(area_lib STATIC
    area.cpp
    area2.cpp
)

target_include_directories(area_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(seminar5 main.cpp)

target_link_libraries(seminar5 PRIVATE area_lib)
