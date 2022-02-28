/* TCP Echo Client Server */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080

int main()
{
    struct sockaddr_in servaddr;
    char buff[1024];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Connect to Server\n");
    printf("Enter Message to Send: ");
    fgets(buff, 1024, stdin);
    send(sock, buff, 1024, 0);
    recv(sock, buff, 1024, 0);
    printf("Server Echo: %s\n", buff);
}