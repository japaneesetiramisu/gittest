#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define P1_READ 0
#define P1_WRITE 1
#define P2_READ 2
#define P2_WRITE 3

#define NUM_PIPES 2

int main(int argc, char *argv[])
{
	int fd[2*NUM_PIPES];
	int val=0,len,len1,len2,i,x,y;
	pid_t pid;
	
	for(i=0;i<NUM_PIPES;++i)
	{
		if(pipe(fd+(i*2))==-1){
			perror("Failed to allocate pipes!\n");
			exit(1);
			}
	}

	if((pid=fork())==-1){
		printf("Fork failed!\n");
		exit(1);
		}

	if(pid==0){
			close(fd[P1_READ]);
			close(fd[P1_WRITE]);
	
			pid=getpid();
			
		if(write(fd[P2_READ],&x,sizeof(x))!=sizeof(x)){
			if(write(fd[P2_READ],&y,sizeof(y))!=sizeof(y)){
				perror("Child:Failed to receive data from parent!");
				exit(1);
			}
		}
			
			len1=read(fd[P2_READ],&x,sizeof(x)); 
			len2=read(fd[P2_READ],&y,sizeof(y));

		if(len1<0){
			if(len2<0){
				perror("Child: Failed read data from pipe!\n");
				exit(1);
			}
		}

		else if((len1 & len2)==0)
			fprintf(stderr,"Child:Read EOF from pipe!\n");

		else{
			printf("Child(%d):Received %d%d\n",pid,x,y);

			val=(x+y);

			printf("Child:Sending %d back to the Parent\n",val);
			if(write(fd[P2_WRITE],&val,sizeof(val))<0)
				{
				perror("Child:Failed to write response value!\n");
				exit(1);
				}
		    	}			
			
			
		}

		
		close(fd[P2_READ]);
		close(fd[P2_WRITE]);

		pid=getpid();
		printf("Enter two values to be added:\n");
		scanf("%d%d",&x,&y);
		
		printf("Parent(%d):Sending %d %d to Child\n",pid,x,y);
		if(write(fd[P1_WRITE],&x,sizeof(x))!=sizeof(x)){
			if(write(fd[P1_WRITE],&y,sizeof(y))!=sizeof(y)){
				perror("Parent:Failed to send value to child!");
				exit(1);
			}
		}
		
		len=read(fd[P1_READ],&val,sizeof(val));
		if(len<0){
			perror("Parent: Failed read value from pipe!\n");
			exit(1);
		}
		else if(len==0)
			fprintf(stderr,"Parent(%d):Read EOF from pipe!\n",pid);
		
		else
			printf("Parent(%d):Received value %d from the pipe!\n",pid,val);

		close(fd[P1_READ]);
		close(fd[P1_WRITE]);

		wait(NULL);
		return 0;
}
