#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h> 
#include<semaphore.h>

char string_ip[100];
sem_t binary_sem;

void *thread_fn(void *arg)
{
	sem_wait(&binary_sem);
	while(strncmp("end",string_ip,3)!=NULL)
	{
		printf("No of characters entered:%d\n",strlen(string_ip) -1);
		sem_wait(&binary_sem);
	}
	pthread_exit(NULL);
	
}
int main(int argc, char *argv[])
{
	int ret;
	pthread_t thread;
	void *thread_result;

	ret= sem_init(&binary_sem, 0, 0);
	if(ret!=0)
	{
		perror("Semaphore Initialisation failed!\n");
		exit(EXIT_FAILURE);
	}
	ret=pthread_create(&thread,NULL,thread_fn,NULL);
	if(ret!=0)
	{
		perror("Thread creation failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter some text('end' to finish):\n");
	while(strncmp("end",string_ip,3)!=NULL)
		{
			fgets(string_ip, 100, stdin);
			sem_post(&binary_sem);
		}
	printf("Waiting for the thread to finish now...\n");
	ret=pthread_join(thread, &thread_result);
	if(ret!=0)
	{
		perror("Thread join failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined!");
	sem_destroy(&binary_sem);
	exit(EXIT_SUCCESS);
}
