#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void func(void)
{
	const int NUM_TIMES=5;
	for(int i=0;i<NUM_TIMES;i++){
		sleep(rand() % 4);
		printf("Done Pass: %d\n",i);
	}	
}
int main(int argc, char *argv[])
{
	printf("I am: %d\n",(int)getpid());
	
	pid_t pid=fork();
	printf("Fork returned: %d\n",(int)pid);
	if(pid<0)
		printf("Fork Failed");

	if(pid==0){
		printf("I am the Child with pid: %d\n",(int)getpid());
		func();
		exit(0);
	}

		printf("I am the parent,waiting for child to end!..\n");
		wait(0);
		printf("Parent ending\n");
	

	
	return 0;
}
