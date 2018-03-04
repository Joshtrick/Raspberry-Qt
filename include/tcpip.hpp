#ifndef TCPIP_HPP
#define TCPIP_HPP

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

class TcpIp
{
public:

  TcpIp();
  ~TcpIp();

  int socket_fd;
  int connected_socket;
  struct sockaddr_in address;

  void server_create(int port, const char *ip);
  void server_listen();
  void server_accept();

  void client_create(int port, const char *ip);
  void client_connect();

  void socket_close(int &socket);

};

#endif
