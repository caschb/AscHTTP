#include <http.h>
#include <iostream>
#include <socket.h>

int main() {
  std::cout << "Hello world!\n";
  auto server = HttpServer(8090);

  while (true) {
    server.handle_connections();
  }

  return 0;
}
