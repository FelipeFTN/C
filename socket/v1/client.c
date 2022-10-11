#include <stdlib.h>
#include <stdio.h>

int main() {
    struct sockaddr_in my_addr;
    int clientSock;
    
    clientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSock < 0) {
        printf("Error while creating the socket\n");
        exit(1);
    }
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(5100);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int clientBind = bind(clientSock, const struct sockaddr *my_addr, sizeof(my_addr));
    if (clientBind < 0) {
        printf("Error in binding\n");
        exit(1);
    }

    int connect(clientSock, struct sockaddr *toaddr, socklen_t addrlen);
    
    
    return 0;
}
