/* TCP Echo Client Server */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in servaddr, cliaddr;
    char buff[1024];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);

    bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Server Started\n");
    listen(sock, 5);
    printf("Listening...\n");
    int len = sizeof(cliaddr);
    int nsock = accept(sock, (struct sockaddr *)&cliaddr, &len);
    printf("Accepted\n");

    recv(nsock, buff, 1024, 0);
    printf("Echo Message: %s\n", buff);
    send(nsock, buff, 1024, 0);
}