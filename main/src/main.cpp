#include <iostream>
#include <socket.h>

int main() {
  std::cout << "Hello world!\n";
  auto socket = Socket();
  socket.bind();
  socket.listen();
  socket.accept();
  return 0;
}
