add_executable(main src/main.cpp)

target_include_directories(main PRIVATE inc)
target_link_libraries(main PRIVATE Socket)
