#ifndef A_SOCKET_H
#define A_SOCKET_H

#include <netinet/in.h>
#include <sys/socket.h>

class Socket {
private:
  int socket_descriptor;
  sockaddr_in socket_address;

public:
  Socket();
  ~Socket();
  void bind();
  void listen();
  void accept();
};

#endif
