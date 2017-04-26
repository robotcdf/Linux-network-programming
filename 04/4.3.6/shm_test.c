#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>
static char msg[]="你好，共享内存\n";
int main(void)
{
	key_t key;
	int semid,shmid;
	char i,*shms,*shmc;
	struct semid_ds *buf;
	int value = 0;
	char buffer[80];
	pid_t p;
	
	key = ftok("/tmp/sem",'a');					/*生成键值*/
	shmid = shmget(key,1024,IPC_CREAT|0604);	/*获得共享内存，大小为1024个字节*/
	
	semid = CreateSem(key,0);					/*建立信号量*/
	
	p = fork();									/*分叉程序*/
	if(p > 0)									/*父进程*/
	{		
		shms = (char *)shmat(shmid,0,0);		/*挂接共享内存*/
		
		memcpy(shms, msg, strlen(msg)+1);		/*复制内容*/
		sleep(10);								/*等待10s，另一个进程将数据读出*/
        printf("父进程semid:%d \n",GetvalueSem(semid));
    	Sem_P(semid);							/*获得共享内存的信号量*/
        printf("父进程Sem_P semid:%d \n",GetvalueSem(semid));
		shmdt(shms);							/*摘除共享内存*/
				
		DestroySem(semid);						/*销毁信号量*/
	}
	else if(p == 0)								/*子进程*/
	{
		shmc = (char *)shmat(shmid,0,0);		/*挂接共享内存*/
        printf("子进程semid:%d \n",GetvalueSem(semid));
		Sem_V(semid);							/*减小信号量*/
        printf("子进程Sem_V semid:%d \n",GetvalueSem(semid));
		printf("共享内存的值为:%s\n",shmc);		/*打印信息*/
		shmdt(shmc);							/*摘除共享内存*/
	}
	return 0;
}
