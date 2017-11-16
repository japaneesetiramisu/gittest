#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

char message[]="Hello World";
void *pthread_fn(void* arg)
{
	printf("thread_function is running %s\n",(char*)arg);
	sleep(3);
	strcpy(message, "Bye");
	pthread_exit("Thank you for the CPU time!\n");
}

int main(int argc, char *argv[])
{
	int res;
	pthread_t thread1;
	void *thread_result;
	
	res = pthread_create(&thread1,NULL,pthread_fn,(void*) message);
	if(res!=0)
	{
		perror("Thread creation failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("Wailting for the thread to finish...\n");
	res=pthread_join(thread1, &thread_result);
	if(res!=0)
	{
		perror("Thread join failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned: %s\n",(char*)thread_result);
	printf("Message is now: %s\n",message);
	exit(EXIT_SUCCESS);
}



