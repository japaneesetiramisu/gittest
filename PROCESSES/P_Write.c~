#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 256
#define TEN_MEG 1024*1024*10

int main(int argc, char *argv[])
{
	int pipefd;
	int open_mode = O_WRONLY;
	int bytes_sent=0;
	int buffer[BUFFER_SIZE+1];
	int ret;

	if(access(FIFO_NAME,F_OK) == -1){
		 ret = mkfifo(FIFO_NAME,0777);
		if(ret!=0){
			fprintf(stderr,"Could not create file %s\n",FIFO_NAME);
			exit(EXIT_FAILURE);
			}
	}

	printf("Process %d opening FIFO in Write only mode:\n",getpid());
	pipefd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d \n",getpid(),pipefd);


	if(pipefd!=-1)
		{
		while(bytes_sent<TEN_MEG)
			{
			ret=write(pipefd, buffer, BUFFER_SIZE);
			if(ret==-1)
				{
				fprintf(stderr,"Write error on pipe!\n");
				exit(EXIT_FAILURE);
				}
			bytes_sent+=ret;
			}
		close(pipefd);
		}
		else 
			exit(EXIT_FAILURE);
		printf("Process %d finished\n",getpid());
		exit(EXIT_SUCCESS);
}
