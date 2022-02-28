/* Implementation of Chat Application using TCP Sockets */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080

int main()
{
    struct sockaddr_in servaddr, cliaddr;
    char buff[1024];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Server Started\n");
    listen(sock, 5);
    printf("Listening...\n");
    int clength = sizeof(cliaddr);
    int nsock = accept(sock, (struct sockaddr *)&cliaddr, &clength);
    printf("Accepted\n");

    printf("Type -stop to Close Session\n");
    while (1)
    {
        recv(nsock, buff, 1024, 0);
        if (strcmp(buff, "-stop\n") == 0)
            break;
        printf("Client: %s\n", buff);
        printf("Type Response: ");
        fgets(buff, 1024, stdin);
        send(nsock, buff, 1024, 0);
        if (strcmp(buff, "-stop\n") == 0)
            break;
    }
    printf("Session Closed\n");
}