#include "tcpip.hpp"

TcpIp::TcpIp()
{

}

TcpIp::~TcpIp()
{

}

//Server creation
void TcpIp::server_create(int port, const char *ip)
{
  int opt = 1;
  //Creating socket file descriptor
  if((this->socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("Server-socket failed");
    exit(EXIT_FAILURE);
  }

  if(setsockopt(this->socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
  {
    perror("Server-setsockopt failed");
    exit(EXIT_FAILURE);
  }
  this->address.sin_family = AF_INET;
  this->address.sin_addr.s_addr = inet_addr(ip);
  this->address.sin_port = htons(port);

  if(bind(this->socket_fd, (struct sockaddr *)&(this->address), sizeof(this->address)) < 0)
  {
    perror("Server-bind failed");
    exit(EXIT_FAILURE);
  }
}

//Server Listening
void TcpIp::server_listen()
{
  if(listen(this->socket_fd, 3) < 0)
  {
    perror("Serverer-listen failed");
    exit(EXIT_FAILURE);
  }
}

//Server acception
void TcpIp::server_accept()
{
  int addr_len = sizeof(this->address);
  if((this->connected_socket = accept(this->socket_fd, (struct sockaddr *)&(this->address),
                                      (socklen_t *)&addr_len) < 0))
  {
    perror("Server-accept failed");
    exit(EXIT_FAILURE);
  }
}

//Client creation
void TcpIp::client_create(int port, const char *ip)
{
  if((this->socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("Client-socket failed");
    exit(EXIT_FAILURE);
  }
  this->address.sin_family = AF_INET;
  this->address.sin_addr.s_addr = inet_addr(ip);
  this->address.sin_port = htons(port);
}

//Client connecting to server
void TcpIp::client_connect()
{
  if(connect(this->socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("Client-connection failed");
    exit(EXIT_FAILURE);
  }
}

//Close a socket
void TcpIp::socket_close(int &socket)
{
  shutdown(socket, SHUT_RD);
}
