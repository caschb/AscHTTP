#ifndef A_SOCKET_H
#define A_SOCKET_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <vector>

class Socket {
  using port_t = uint32_t;

private:
  class Address {
  public:
    Address(port_t port);
    sockaddr_in *get_address_pointer();
    size_t get_address_size();

  private:
    port_t port;
    sockaddr_in socket_address;
  };

public:
  Socket();
  Socket(int socket_descriptor);
  ~Socket();
  void bind(port_t port = 8080);
  void listen();
  Socket accept();
  void send(Socket &destination, const std::vector<char> &data);
  std::vector<char> recv(Socket &source);

  int get_socket_descriptor();

private:
  int socket_descriptor;
  port_t port;
};

#endif
