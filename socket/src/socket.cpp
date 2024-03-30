#include <cstdio>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <socket.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

Socket::Address::Address(port_t port) : port(port) {
  socket_address.sin_family = AF_INET;
  socket_address.sin_port = htons(port);
  socket_address.sin_addr.s_addr = INADDR_ANY;
}

sockaddr_in *Socket::Address::get_address_pointer() { return &socket_address; }

size_t Socket::Address::get_address_size() { return sizeof(socket_address); }

Socket::Socket() : port(-1) {
  socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_descriptor == -1) {
    std::perror("Error creating socket");
  }
}

Socket::Socket(int socket_descriptor) : socket_descriptor(socket_descriptor) {}

Socket::~Socket() {
  auto result = close(socket_descriptor);
  if (result) {
    std::perror("Error closing socket");
  }
}

void Socket::bind(port_t port) {
  this->port = port;
  Address address(port);
  auto result = ::bind(socket_descriptor,
                       (const struct sockaddr *)address.get_address_pointer(),
                       address.get_address_size());
  if (result) {
    std::perror("Error binding to address");
  }
}

void Socket::listen() {
  auto result = ::listen(socket_descriptor, 5);
  if (result) {
    std::perror("Error listening to socket");
  }
}

Socket Socket::accept() {
  sockaddr_storage client_address;
  socklen_t socklen = sizeof(client_address);
  auto client_socket_descriptor =
      ::accept(socket_descriptor, (sockaddr *)&client_address, &socklen);
  if (client_socket_descriptor == -1) {
    std::perror("Error listening to socket");
  }
  return Socket(client_socket_descriptor);
}

int Socket::get_socket_descriptor() { return socket_descriptor; }

std::vector<char> Socket::recv(Socket &source) {
  std::vector<char> data(1024);
  auto read_bytes =
      ::recv(source.get_socket_descriptor(), &data[0], data.size(), 0);
  return data;
}

void Socket::send(Socket &destination, const std::vector<char> &data) {
  auto sent_bytes =
      ::send(destination.get_socket_descriptor(), &data[0], data.size(), 0);
}
