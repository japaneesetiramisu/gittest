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
	
	if((fp=fopen("data","aw"))==NULL)
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

	for(i=0,ch='a';i<10;ch++,i++)
	{
		semop(id,&v,1);
		ch=fgetc(fp);
		printf("%c ",ch);
	}
	printf("READING DONE...\n");
	
}
