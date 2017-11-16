#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h> 
#include<semaphore.h>

int a,b;
sem_t input2calCsem;
sem_t calCtoinputsem;
void *input_thread(void *arg)
{
	printf("Enter value for a:\n");
	scanf("%d",&a);
	printf("Enter value for b:\n");
	scanf("%d",&b);
}
void *catch_thread(void *arg)
{
	int sum;
	sum=a+b;
	printf("The sum is: %d\n",sum);
}
int main(int argc, char *argv[])
{
	pthread_t inputid, calctid;
	sem_init(&input2calCsem, 0, 0);
	sem_init(&calCtoinputsem, 0, 1);
	pthread_create(&inputid, NULL, input_thread, NULL);
	pthread_create(&calctid, NULL, catch_thread, NULL);
	pthread_join(inputid, NULL);
	pthread_join(calctid, NULL);
	return 0;
}
