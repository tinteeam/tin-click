cmake_minimum_required(VERSION 3.10)

project(tin_clicker
    LANGUAGES CXX
    VERSION 0.1
)

set(PROJECT_STAGE "alpha1")

add_subdirectory(src)

add_executable(tin-clicker src/main.cpp)

target_link_directories(tin-clicker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)