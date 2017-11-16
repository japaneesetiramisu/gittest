#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h> 

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void *mutex_fn(void *arg)
{
	pthread_mutex_lock(&lock);
	unsigned long i=0;
	counter+=1;
	printf("\n Job %d has started\n",counter);
	for(i=0;i<(0xffffffff);i++);
	printf("\njob %d has been finished\n",counter);
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(int argc, char *argv[])
{
	int i=0;
	int error;
	if(pthread_mutex_init(&lock,NULL)!=0)
	{
		perror("Mutex initialisation failed!\n");
		exit(EXIT_FAILURE);
	}
	while(i<2)
	{
		error=pthread_create(&(tid[i]), NULL, &mutex_fn, NULL);
		if(error!=0)
		printf("Thread cant be created [%s]",strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	
	pthread_mutex_destroy(&lock);
	return 0;
}

  
