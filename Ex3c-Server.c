/* Implementation of File Transfer using TCP Socket */

#include <stdio.h>
#include <string.h>
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
  FILE *fp = fopen(buff, "w");
  printf("File Received: %s\n\n", buff);
  
  while(recv(nsock, buff, 1024, 0))
  {
    printf("%s", buff);
    fputs(buff, fp);
  }
}