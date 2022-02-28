/* Domain Name Server Application using UDP Sockets */

#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 8080

int main()
{
  char buffer[1024], *ip;
  struct sockaddr_in servaddr, cliaddr;

  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);

  bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  int len = sizeof(cliaddr);

  int n = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&cliaddr, &len);
  buffer[n] = '\0';
  printf("Domain Received: %s\n", buffer);

  struct hostent *host_entry = gethostbyname(buffer);
  ip = (host_entry == NULL) ? "IP Not Found!" : inet_ntoa(*((struct in_addr *)host_entry->h_addr));

  sendto(sock, ip, 1024, 0, (struct sockaddr *)&cliaddr, len);
  printf("IP Sent: %s\n", ip);
}