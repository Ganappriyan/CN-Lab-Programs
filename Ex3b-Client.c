/* Implementation of Chat Application using TCP Sockets */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080

int main()
{
    struct hostent *server;
    struct sockaddr_in servaddr;
    char buff[1024];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    
    connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Connected to Server\n");
    printf("Type -stop to Close Session\n");
    while (1)
    {
        printf("Type Message: ");
        fgets(buff, 1024, stdin);
        send(sock, buff, 1024, 0);
        if (strcmp(buff, "-stop\n") == 0)
            break;
        recv(sock, buff, 1024, 0);
        if (strcmp(buff, "-stop\n") == 0)
            break;
        printf("Server: %s\n", buff);
    }
    printf("Session Closed\n");
}