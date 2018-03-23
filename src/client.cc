#include "socket.h"
#include "unit.h"
#include "io.h"
#include "BaseServer.h"

#define SERVER_ADDRESS	"192.168.77.132"
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
	int		fd = 0;
	BaseServer_t	sv;

	printf("Client Running...\n");

	if ((fd = sv.Connect(SERVER_ADDRESS, SERVER_PORT)) < 0)
	{
		exit(0);
	}

	client_work(fd);

	return 0;
}
