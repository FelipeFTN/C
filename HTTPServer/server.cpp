#include "server.h"

#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <sys/un.h>

Server::Server() {}

int Server::start_server() {
  // Create socket
  if ((server_socket = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
    std::cerr << "Failed to create socket." << std::endl;
    return -1;
  }

  // Set up server address
  struct sockaddr_un server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sun_family = AF_UNIX;
  strcpy(server_addr.sun_path, "/tmp/my_server.sock");

  // Bind the socket to the server address
  if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Failed to bind socket." << std::endl;
    close(server_socket);
    return -1;
  }

  // Listen for connection
  if (listen(server_socket, 10) < 0) {
    std::cerr << "Failed to listen on socket." << std::endl;
    close(server_socket);
    return -1;
  }

  std::cout << "Server is listening on /tmp/my_server.sock" << std::endl;

  return 0;
}

int Server::stop_server() {
  if ((close(server_socket)) < 0) {
    return -1;
  }
  return 0;
}

int Server::listen_client() {
  while (true) {
    // Accept a client connection
    struct sockaddr_un client_addr;
    socklen_t client_addr_length = sizeof(client_addr); 
    if ((client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &client_addr_length)) < 0) {
      std::cerr << "Failed to accept client connection." << std::endl;
      close(server_socket);
      return -1;
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if ((recv(client_socket, buffer, sizeof(buffer) - 1, 0)) < 0) {
      std::cerr << "Failed to read from client socket." << std::endl;
      close(client_socket);
      close(server_socket);
      return -1;
    }

    std::cout << "Received request: " << buffer << std::endl;
  }
  return 0;
}


int Server::send_client(char *response) {
  if (response == nullptr) {
    response = default_response;
  }

  if ((send(client_socket, response, strlen(response), 0)) < 0) {
    std::cerr << "Failed to send response to client." << std::endl;
    close(client_socket);
    close(server_socket);
    return -1;
  }

  return 0;
}

