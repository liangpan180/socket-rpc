#include "socket.h"
#include "unit.h"
#include "io.h"
#include "BaseServer.h"

#define MAX_BUF_LEN	1024

void handle_client(int clientfd)
{
	char		buf[MAX_BUF_LEN] = {0};
	size_t		len = 0;

	for ( ; ;)
	{
		len = readline(clientfd, &buf, MAX_BUF_LEN);
		if (len <= 0)
		{
			printf("Read Buf Err %d\n", len);
			return;
		}

		printf("CLIENT_SAY: %s", buf);

		writen(clientfd, &buf, strlen(buf));

		memset(buf, 0, MAX_BUF_LEN);
	}

	return;
}

int main(int argc, char** argv)
{
	BaseServer_t 	sv;

	printf("Server Running...\n");

	if (sv.Bind() < 0)
	{
		exit(1);
	}

	if (sv.Listen() < 0)
	{
		exit(1);
	}

	sv.set_handle_func(handle_client);

	sv.Run();

	return 0;
}
