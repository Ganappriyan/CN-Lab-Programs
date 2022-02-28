/* ARP/RARP Simulation in UDP */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080

struct IPmac
{
  char ip[100];
  char mac[100];
};

int main()
{
  char buffer[1024];
  struct sockaddr_in servaddr, cliaddr;

  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);
  servaddr.sin_family = AF_INET;

  bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  int len = sizeof(cliaddr), i;

  struct IPmac in[3] = {{"10.1.1.8", "44:dd:22:11:33"},
                        {"127.0.0.1", "33:aa:fe:4e:2d"},
                        {"10.1.8.5", "23:a3:5d:33:9d"}};

  while (1)
  {
    int n = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    if (strcmp(buffer, "-stop") == 0)
      break;

    if (strcmp(buffer, "IP") == 0)
    {
      n = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&cliaddr, &len);
      buffer[n] = '\0';
      printf("IP Received: %s\n", buffer);
      for (i = 0; i < 3; i++)
      {
        if (strcmp(buffer, in[i].ip) == 0)
        {
          printf("MAC Sent: %s\n", in[i].mac);
          sendto(sock, in[i].mac, 1024, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
          break;
        }
      }
      if (i == 3)
        sendto(sock, "Not Found", 1024, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }
    else
    {
      n = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&cliaddr, &len);
      buffer[n] = '\0';
      printf("MAC Received: %s\n", buffer);
      for (i = 0; i < 3; i++)
      {
        if (strcmp(buffer, in[i].mac) == 0)
        {
          printf("IP Sent: %s\n", in[i].ip);
          sendto(sock, in[i].ip, 1024, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
          break;
        }
      }
      if (i == 3)
        sendto(sock, "Not Found", 1024, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }
  }
  close(sock);
}