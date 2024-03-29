#include <cstdio>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <socket.h>

Socket::Socket() {
  socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_descriptor == -1) {
    std::perror("Error creating socket");
  }
  socket_address.sin_family = AF_INET;
  socket_address.sin_port = htons(8080);
  socket_address.sin_addr.s_addr = INADDR_ANY;
}

Socket::~Socket() {
  auto result = close(socket_descriptor);
  if (result) {
    std::perror("Error closing socket");
  }
}

void Socket::bind() {
  auto result = ::bind(socket_descriptor, (struct sockaddr *)&socket_address,
                       sizeof(socket_address));
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

void Socket::accept() {
  auto client_socket_descriptor = ::accept(socket_descriptor, nullptr, nullptr);
  if (client_socket_descriptor == -1) {
    std::perror("Error listening to socket");
  }
  char buffer[1024] = {0};
  recv(client_socket_descriptor, buffer, sizeof(buffer), 0);
  std::cout << buffer << '\n';
}
