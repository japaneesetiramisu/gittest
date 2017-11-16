#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count = 0;
void *increment_fn(void *arg)
{
	while(1){
	count++;
	printf("increment is:%d\n",count);
	}
}

void *decrement_fn(void *arg)
{
	while(1){
	count--;
	printf("deccrement is:%d\n",count);
	}
}

int main(int argc, char *argv[])
{
	int ret1,ret2;
	pthread_t tid1,tid2;
	ret1=pthread_create(&tid1, NULL, increment_fn, NULL);
	if(ret1!=0)
	{
		perror("Thread creation failed!\n");
		exit(EXIT_FAILURE);
	}
	ret1=pthread_create(&tid2, NULL, decrement_fn, NULL);
	if(ret2!=0)
	{
		perror("Thread creation failed!\n");
		exit(EXIT_FAILURE);
	}
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	exit(EXIT_SUCCESS);
}
