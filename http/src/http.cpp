#include <http.h>
#include <iostream>
#include <socket.h>
#include <vector>

HttpServer::HttpServer(uint32_t port) : port(port) {
  server_socket.bind(port);
  server_socket.listen();
}
void HttpServer::handle_connections() {
  auto client = server_socket.accept();
  auto data = server_socket.recv(client);
  auto req = std::string(data.begin(), data.end());
  std::cout << req << '\n';
  auto response = std::string("HTTP/1.0 200 OK\n\nHello world!");
  auto send_data = std::vector(response.begin(), response.end());
  server_socket.send(client, send_data);
}
