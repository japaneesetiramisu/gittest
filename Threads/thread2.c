#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_fn(void *arg)
{
	printf("Hello Thread!\n");
}
int main(int argc, char *argv[])
{
	int ret;
	pthread_t tid;
	printf("Before Thread\n");
	ret=pthread_create(&tid, NULL, thread_fn, NULL);
	if(ret!=0)
	{
		perror("Thread creation failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("After Thread\n");
	exit(EXIT_SUCCESS);
}
