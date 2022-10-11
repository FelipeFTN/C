#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct sockaddr_in server_info = {};

    server_info.sin_family = AF_INET;
    server_info.sin_addr.s_addr = INADDR_ANY;
    server_info.sin_port = htons(9222);

    int s_socket = socket(AF_INET, SOCK_STREAM, 0);
    char buffer[1024] = {0};
    int opt = 1;
    int client;

    if (s_socket < 0) {
        printf("Error while creating socket\n");
        return -1;
    }

    socklen_t server_info_len = sizeof(server_info);

    if(setsockopt(s_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error while setting address for reuse\n");
        return -1;
    }
    
    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    if (bind(s_socket, (struct sockaddr*)&server_info, server_info_len) < 0) {
        printf("Error while binding socket\n");
        return -1;
    }

    // int listen(int sockfd, int backlog);
    if (listen(s_socket, 3) < 0) {
        printf("Error while listening socket\n");
        return -1;
    }

    // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
    if (client = accept(s_socket, (struct sockaddr*)&server_info, &server_info_len) < 0) {
        printf("Error while accepting socket request\n");
        return -1;
    }

    int valread = read(client, buffer, 1024);
    printf("%s\n", buffer);

    char *hello = "Hello World!\n";
    send(client, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    close(client);

    return 0;
}
