#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

class Server {
public:
  Server();

public:
  int start_server();
  int stop_server();
  int listen_client();
  int send_client(std::string response);

private:
  // Sockets
  int server_socket;
  int client_socket;

  // Address
  int port;
  int host;

  // Response
  std::string default_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello, World!";
};
