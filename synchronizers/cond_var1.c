#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h> 

pthread_t tid[2];
int counter=0;
pthread_cond_t condition1,condition2;
pthread_mutex_t lock1,lock2;

void *mutex_cond_fn1(void *arg)
{
	pthread_mutex_lock(&lock1);
//	pthread_cond_wait(&condition1, &lock1);
	unsigned long i=0;
	counter+=1;
	printf("\n Job %d has started\n",counter);
	for(i=0;i<(0xffffffff);i++);
	printf("\njob %d has been finished\n",counter);
	pthread_mutex_unlock(&lock2);
//	pthread_cond_signal(&condition2);
	
	return NULL;
}

void *mutex_cond_fn2(void *arg)
{
	pthread_mutex_lock(&lock2);
//	pthread_cond_wait(&condition2, &lock2);
	unsigned long i=2;
	counter+=1;
	printf("\n Job %d has started\n",counter);
	for(i=0;i<(0xffffffff);i++);
	printf("\njob %d has been finished\n",counter);
	pthread_mutex_unlock(&lock1);
//	pthread_cond_signal(&condition1);
	
	return NULL;
}
int main(int argc, char *argv[])
{
	int i=0;
	int error;
	if(pthread_mutex_init(&lock1, NULL)!=0)
	{
		perror("Mutex1 initialisation failed!\n");
		exit(EXIT_FAILURE);
	}

	if(pthread_mutex_init(&lock2, NULL)!=0)
	{
		perror("Mutex2 initialisation failed!\n");
		exit(EXIT_FAILURE);
	}
	
	{
		error=pthread_create(&(tid[0]), NULL, &mutex_cond_fn1, NULL);
		if(error!=0)
		printf("Thread cant be created [%s]",strerror(error));
		i++;
	}
	{
		error=pthread_create(&(tid[1]), NULL, &mutex_cond_fn2, NULL);
		if(error!=0)
		printf("Thread cant be created [%s]",strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	
	pthread_exit(NULL);
//	pthread_cond_destroy(&condition1);
//	pthread_cond_destroy(&condition2);
	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	return 0;
}
