#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int sd;
	char buffer[1024];
	struct sockaddr_in servAddr;
	socklen_t addr_size;

	sd = socket(PF_INET, SOCK_STREAM, 0);

	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(5000);
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	memset(servAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	addr_size = sizeof servAddr;
	connect(sd, (struct  sockaddr *) &servAddr, addr_size);

	recv(sd, buffer, 1024, 0);
	printf("recv", buffer);

	return 0;
}
