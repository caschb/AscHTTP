add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE Socket)
target_link_libraries(main PRIVATE HttpServer)
