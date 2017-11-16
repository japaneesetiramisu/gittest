#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int ret=mkfifo("/tmp/my_fifo",0777);
	if(ret==0){
	printf("FIFO created\n");
	exit(1);
	}
}
