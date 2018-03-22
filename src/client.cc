#include "socket.h"
#include "unit.h"
#include "io.h"

#define SERVER_ADDRESS	"192.168.77.131"
#define SERVER_PORT	9999
#define MAX_LEN		1024

int client_work(int fd)
{
	char gbuf[MAX_LEN] = {0};	
	char rbuf[MAX_LEN] = {0};	

	printf("CLENT_SAY:");
	while (fgets(gbuf, MAX_LEN, stdin) != NULL)
	{
		writen(fd, &gbuf, strlen(gbuf));
		readline(fd, &rbuf, MAX_LEN);
		printf("SERVER_SAY: %s", rbuf);
		memset(gbuf, 0, MAX_LEN);
		memset(rbuf, 0, MAX_LEN);
		printf("CLENT_SAY:");
	}
}

int main(int argc, char** argv)
{
	int		connectfd = 0;
	SockAddr_t	caddr;
	int		ret = 0;

	printf("Client Running...\n");

	connectfd = socket(AF_INET, SOCK_STREAM, 0);
	if (connectfd < 0)
	{
		printf("Socket Err\n");
		exit(1);
	}

	bzero(&caddr, sizeof(caddr));
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, SERVER_ADDRESS, &caddr.sin_addr);

	ret = connect(connectfd, (struct sockaddr*)&caddr, sizeof(caddr));
	if (ret != 0)
	{
		printf("Client Connect failed (%d)\n", errno);
		exit(0);
	}

	client_work(connectfd);

	return 0;
}
