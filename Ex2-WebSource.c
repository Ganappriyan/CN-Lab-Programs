/* Write a Web Client Program to download a Web Page using TCP Sockets */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
  char host[253] = "pacolleges.org", req[1024], buff[2];
  struct hostent *server;
  struct sockaddr_in servaddr;

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  server = gethostbyname(host);

  memcpy(&servaddr.sin_addr, server->h_addr_list[0], server->h_length);
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);

  connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  printf("Connected\n");

  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
  send(sock, req, strlen(req), 0);
  printf("Request Sent\n");

  while (recv(sock, buff, 1, 0) != 0)
    printf("%s", buff);
}
