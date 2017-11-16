#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include"library.h"

void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do{
	printf("> ");//Its a promt
	line=lsh_read_line;
	args=lsh_split_line;
	status=lsh_execute(args);
	free(line);
	free(args);
	}while(status);
	return 0;
}
int main(int argc, char **argv)
{
  	lsh_loop();

	return EXIT_SUCCESS;
}
