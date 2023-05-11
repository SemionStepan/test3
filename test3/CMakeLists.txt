cmake_minimum_required(VERSION 3.5)

project(test3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test3 main.cpp)

install(TARGETS test3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
