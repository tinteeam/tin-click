# Main CMakeLists.txt for the Tin Click project.
# Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
cmake_minimum_required(VERSION 3.10)

project(tin_clicker
    LANGUAGES CXX
    VERSION 0.1
)

set(PROJECT_STAGE "alpha1")
set(WIN32_EXECUTABLE true)

add_subdirectory(src)

add_executable(tin-clicker WIN32 src/main.cpp)

target_link_libraries(tin-clicker PRIVATE tin-click PUBLIC d2d1 dwrite windowscodecs)
target_include_directories(tin-clicker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)