cmake_minimum_required(VERSION 3.10.2)
project(simple_dbus)
set(CMAKE_BUILD_TYPE Debug)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(simple_dbus main.cpp)

find_library(SDBUS_LIBS sdbus-c++)

target_link_libraries(simple_dbus ${SDBUS_LIBS} ${CONAN_LIBS})
