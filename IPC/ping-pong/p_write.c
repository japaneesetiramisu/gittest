#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
	struct sembuf v;
	char ch;
	FILE *fp;
	int id,i;

	if((fp=fopen("data","w"))==NULL)
	{
		perror("open");
		return 0;
	}
	id=semget(10,4,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	v.sem_num=2;
	v.sem_op=0;
	v.sem_fig=0;
	printf("Checking for availability...\n");
	semop(id,&v,1);
	semctl(id,2,SETVAL,1);
	printf("Get access...\n");
	for(i=0,ch='a';i<10;ch++,i++)
	{
		fputc(ch,fp);
		sleep(1);
	}
	semctl(id,2,SETVAL,0);
	
	printf("WRITING DONE...\n");
}
