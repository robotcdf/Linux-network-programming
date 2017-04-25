#include<stdio.h>
#include<unistd.h>
int main(void)
{
	char *args[]={"/bin/echo", "Hello execve!"};
	printf("系统分配的进程号是：%d\n",getpid());
//	if(execve("/bin/ls",args,NULL)<0)
	if(execve("/bin/echo", args,NULL)<0)
		printf("创建进程出错！\n");
		
	return 0;
}
