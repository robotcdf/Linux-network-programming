/*
 *broadcast_client.c - 多播的客户端
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#define MCAST_PORT 8888;
#define MCAST_ADDR "224.0.0.88"                 /*一个局部连接多播地址，路由器不进行转发*/
#define MCAST_INTERVAL 5                            /*发送时间间隔*/
#define BUFF_SIZE 256                               /*接收缓冲区大小*/
int main(int argc, char* argv[])
{
    int s;                                          /*套接字文件描述符*/
    struct sockaddr_in local_addr;                  /*本地地址*/
    int err = -1;

    s = socket(AF_INET, SOCK_DERAM, 0);             /*建立套接字*/
    if(s == -1)
    {
        perror("socket()");
        return -1;
    }

                                                    /*初始化地址*/
    memset(&local_addr, 0, sizeof(local_addr));


    return 0;

}

