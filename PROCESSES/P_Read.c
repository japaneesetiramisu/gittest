#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
	int pipefd;
	int open_mode = O_RDONLY;
	int bytes_read=0;
	int buffer[BUFFER_SIZE+1];
	int ret;
	memset(buffer, '\0', BUFFER_SIZE);
	
	printf("Process %d opening FIFO in Read only mode:\n",getpid());
	pipefd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d \n",getpid(),pipefd);

	if(pipefd!=-1){
			do{
				ret= read(pipefd, buffer, BUFFER_SIZE);	
				bytes_read+=ret;
			  }while(ret>0);
			
		close(pipefd);
		}
	else
		exit(EXIT_FAILURE);
	printf("Process %d  finished, %d bytes read\n",getpid(),bytes_read);
	exit(EXIT_SUCCESS);
}
