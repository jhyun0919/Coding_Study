#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int sock_connect(char **ip, char **port)
{
	int sock;
	struct sockaddr_in serv_addr;

	sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(*ip);
    serv_addr.sin_port=htons(atoi(*port));

	if(connect(sock,(struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");

	return sock;
}

int send_msg(int sock, char msg[8])
{
	int str_len;
	str_len = write(sock, msg, strlen(msg));
	if(str_len == -1)
		error_handling("send_msg error");

//	memset(&msg, 0, sizeof(msg));

	return str_len;
}

int recv_msg(int sock, char msg[5])
{
	int str_len;
	str_len = read(sock, msg, sizeof(msg));
	if(str_len < 0)
		error_handling("recv_msg error");
	
	memset(&msg, 0, sizeof(msg));

	return str_len;
}
