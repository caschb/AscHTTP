add_library(HttpServer src/http.cpp)

target_include_directories(HttpServer PUBLIC inc/)
target_link_libraries(HttpServer PRIVATE Socket)
