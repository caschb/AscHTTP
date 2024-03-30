#include <iostream>
#include <socket.h>

int main() {
  std::cout << "Hello world!\n";
  auto socket = Socket();
  socket.bind();
  socket.listen();

  while (true) {
    auto client = socket.accept();
    auto data = socket.recv(client);
    auto req = std::string(data.begin(), data.end());
    std::cout << req << '\n';
    auto response = std::string("HTTP/1.0 200 OK\n\nHello world!");
    auto send_data = std::vector(response.begin(), response.end());

    socket.send(client, send_data);
  }

  return 0;
}
