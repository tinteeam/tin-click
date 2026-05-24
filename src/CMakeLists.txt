#
# CMakeLists.txt for the src directory of the Tin Click project.
# Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.

add_library(tin-click include/Window.cpp)

target_include_directories(tin-click PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)