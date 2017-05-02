#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>						/*包含socket()/bind()*/
#include <netinet/in.h>						/*包含struct sockaddr_in*/
#include <string.h>							/*包含memset()*/
#define PORT_SERV 8888						/*服务器端口*/
#define NUM_DATA 100                        /*接收缓冲区数量*/
#define LENGTH 1024							/*缓冲区大小*/
static char buff_send[LENGTH];              /*接收缓冲区*/
static void udpclie_echo(int s, struct sockaddr*to)
{
	char buff_init[BUFF_LEN] = "UDP TEST";		/*发送给服务器的测试数据*/
	struct sockaddr_in from;					/*服务器地址*/
	socklen_t len = sizeof(*to);						/*地址长度*/
    int i = 0;                                  /*计数*/
    for(i=0; i< NUM_DATA; i++)
    {
        *((int*) &buff_send[0]) = htonl(i);     /*将输据标记打包*/
        memcpy(&buff_send[4], buff_init, sizeof(buff_init));   
                                                /*将数据复制到发送缓冲区*/
        snedto(s, &bufff_send[0], NUM_DATA, 0, to, len); /*发送数据*/
	    //sendto(s, buff, BUFF_LEN, 0, to, len);		/*发送给服务器*/
    }
	recvfrom(s, buff, BUFF_LEN, 0, (struct sockaddr*)&from, &len);	
												/*从服务器接收数据*/
	printf("recved:%s\n",buff);					/*打印数据*/
}

int main(int argc, char*argv[])
{
	int s;											/*套接字文件描述符*/
	struct sockaddr_in addr_serv;					/*地址结构*/
	
	s = socket(AF_INET, SOCK_DGRAM, 0);			/*建立数据报套接字*/
	
	memset(&addr_serv, 0, sizeof(addr_serv));		/*清空地址结构*/
	addr_serv.sin_family = AF_INET;				/*地址类型为AF_INET*/
	addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);	/*任意本地地址*/
	addr_serv.sin_port = htons(PORT_SERV);			/*服务器端口*/
	
	udpclie_echo(s, (struct sockaddr*)&addr_serv);	/*客户端回显程序*/
	
	close(s);
	return 0;	
}
