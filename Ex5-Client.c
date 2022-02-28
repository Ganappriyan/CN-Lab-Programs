/* ARP/RARP Simulation in UDP */

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

	while (1)
	{
		printf("1. ARP\n2. RARP\n3. Exit\nEnter Choice: ");
		scanf(" %c", &buffer[0]);
		switch (buffer[0])
		{
		case '1':
			sendto(sock, "IP", 1024, 0, (struct sockaddr *)NULL, sizeof(servaddr));

			printf("\nEnter IP: ");
			scanf(" %s", buffer);
			sendto(sock, buffer, 1024, 0, (struct sockaddr *)NULL, sizeof(servaddr));

			recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)NULL, NULL);
			printf("\nMAC: %s\n\n", buffer);
			break;

		case '2':
			sendto(sock, "MAC", 1024, 0, (struct sockaddr *)NULL, sizeof(servaddr));

			printf("\nEnter MAC: ");
			scanf(" %s", buffer);
			sendto(sock, buffer, 1024, 0, (struct sockaddr *)NULL, sizeof(servaddr));

			recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)NULL, NULL);
			printf("\nIP: %s\n\n", buffer);
			break;

		case '3':
			sendto(sock, "-stop", 1024, 0, (struct sockaddr *)NULL, sizeof(servaddr));
			close(sock);
			return 0;

		default:
			printf("\nInvalid Option\n");
		}
	}
}
