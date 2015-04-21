#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int sd, newsd;
	char buffer[1024];
	struct sockaddr_in servAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	sd = socket(PF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	bind(sd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(sd, 5) == 0)
		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage;
	newsd = accept(sd, (struct sockaddr *) &serverStorage, &addr_size);

	strcpy(buffer, "Hello");
	send(newsd, buffer, 13, 0);

	return 0;
}
