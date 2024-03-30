#ifndef HTTP_H
#define HTTP_H
#include <socket.h>
#include <vector>

class HttpServer {

private:
  Socket server_socket;
  uint32_t port;

public:
  HttpServer(uint32_t port = 8080);
  void handle_connections();
  std::vector<char> receive_data();
};

#endif
