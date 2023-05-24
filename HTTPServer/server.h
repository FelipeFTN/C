#pragma once

class Server {
public:
  Server();

public:
  int start_server();
  int stop_server();
  int listen_client();
  int send_client(char *response);

private:
  // Sockets
  int server_socket;
  int client_socket;

  // Address
  int port;
  int host;

  // Response
  char* default_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello, World!";
};
