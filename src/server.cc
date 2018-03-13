#include<stdio.h>
#include "socket.h"
#include "unit.h"

#define SERVER_PORT 9088

int handle_client(int clientfd)
{
	printf("Client connected..\n");
	return 0;
}

int main(int argc, char** argv)
{
	int		listenfd = 0, connectfd = 0;
	socklen_t	clen = 0;
	pid_t		cpid;
	SockAddr_t	saddr, caddr; 
	int		ret = 0;
	int		count = 0;

	printf("Server Running...\n");

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
	{
		printf("Socket Err\n");
		exit(1);
	}

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	saddr.sin_port = htons(SERVER_PORT);	

	ret = bind(listenfd, (struct sockaddr*)&saddr, sizeof(saddr));
	if (ret != 0)
	{
		printf("Bind Error (%d)\n", errno);
		exit(1);
	}	

	ret = listen(listenfd, 5);
	if (ret != 0)
	{
		printf("Listen Error (%d)\n", errno);
		exit(1);
	}

	for( ; ; )
	{
		clen = sizeof(caddr);	
		connectfd = accept(listenfd, (struct sockaddr*)&caddr, &clen);

		cpid = fork();
		if (cpid == 0) // Child Progress
		{
			close(listenfd);
			handle_client(connectfd);
			close(connectfd);
			exit(0);
		} else
		{
			printf("Clinet Num (%d)", ++count);
			close(connectfd);
		}
	}

	return 0;
}
