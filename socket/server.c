#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int serverSock;
    int serverSockOPT;
    struct sockaddr_in serverAddress;
    int yes = 1;

    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0) {
        printf("Error while creating the socket\n");
        exit(1);
    }
    
    serverSockOPT = setsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    if (serverSockOPT < 0) {
        printf("Error while creating socket OPT\n");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(5100);

    int serverBind = bind(serverSock, (struct sockaddr) &serverAddress, sizeof(struct sockaddr_in));
    if (serverBind < 0) {
        printf("Error in binding\n");
        exit(1);
    }

    int serverListen = listen(serverSocket, 5);
    if (serverListen < 0) {
        printf("Error while listening\n");
        exit(1);
    }

    int serverAccept = accept(serverSocket, (struct sockaddr) &serverAddress, sizeof(struct sockaddr_in));
    if (serverAccept < 0) {
        printf("Error while accepting client\n");
    }

    return 0;
}
