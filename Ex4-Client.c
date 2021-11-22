/* Domain Name Server Application using UDP Sockets */

#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080

int main()
{
  char buffer[1024];
  struct sockaddr_in servaddr;

  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);
  servaddr.sin_family = AF_INET;
  int sock = socket(AF_INET, SOCK_DGRAM, 0);

  connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  printf("Enter Domain Name: ");
  scanf(" %s", buffer);
  sendto(sock, buffer, 1024, 0, (struct sockaddr *)NULL, sizeof(servaddr));

  recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)NULL, NULL);
  printf("IP: %s\n", buffer);
}