#include <WinSock2.h>
#include <stdlib.h>
#include <stdio.h>

void error_handling(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int sock_connect(char **ip, char **port)
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
		error_handling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(hSocket==INVALID_SOCKET)
		error_handling("hSocketet() error!");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=inet_addr(*ip);
	servAddr.sin_port=htons(atoi(*port));

	if(connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr))==SOCKET_ERROR)
		error_handling("connect() error!");

	return hSocket;
}

int send_msg(SOCKET sock, char* send_msg)
{
	int str_len;
	str_len = send(sock, send_msg, sizeof(send_msg)-1, 0);
	if(str_len == -1)
		error_handling("send_msg error");

	return str_len;
}

int recv_msg(SOCKET sock)
{
	int str_len;
	char* recv_msg;
	str_len = recv(sock, recv_msg, sizeof(recv_msg)-1, 0);
	if(str_len == -1)
		error_handling("recv_msg error");

	return str_len;
}