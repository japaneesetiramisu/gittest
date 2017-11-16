#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	printf("I am: %d\n",(int)getpid());
	
	pid_t pid=fork();
	printf("Fork returned: %d\n",(int)pid);
	if(pid<0)
		perror("Fork Failed");

	if(pid==0)
		printf("I am the Child with pid: %d\n",(int)getpid());

	else if(pid>0)
		printf("I am the parent\n");
	

	//printf("I am: %d\n",(int)getpid());
	return 0;
}
