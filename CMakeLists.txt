cmake_minimum_required(VERSION 3.20)

project(AscHTTP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(socket)
add_subdirectory(http)
add_subdirectory(main)
