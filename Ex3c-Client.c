/* Implementation of File Transfer using TCP Socket */

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
  char buffer[1024];
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  printf("Connected to Server\n");

  printf("Enter Old File Name: ");
  scanf("%s", buffer);
  FILE *fp = fopen(buffer, "r");
  if (fp == NULL)
  {
    printf("Cannot Open File\n");
    return -1;
  }

  printf("Enter New File Name: ");
  scanf("%s", buffer);
  send(sock, buffer, 1024, 0);

  while (fgets(buffer, 1024, fp) != NULL)
    send(sock, buffer, 1024, 0);
}