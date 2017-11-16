#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h> 

pthreads_rwlock_t rw1;
counter=0;
void *incthread(void *arg)
{
	pthread_rwlock_wrlock(&rw1);
	unsigned long i=0;
	counter+=1;
	printf("\n Job %d has started\n",counter);
	for(i=0;i<(0xffffffff);i++);
	printf("\njob %d has been finished\n",counter);
	pthread_rwlock_unlock(&rw1);
}

void *lcdthread(void *arg)
{
	pthread_rwlock_rdlock(&rw1);
	printf("printf initiating reading from LCD\n");
	pthread_rwlock_unlock(&rw1);
}

void *serialthread(void *arg)
{
	int i,sum=0;
	pthread_rwlock_rdlock(&rw1);
	for(i=0;i<10;){
		printf("Value of sum is:%d\n",sum+=i);
		i++;
		}
	pthread_rwlock_unlock(&rw1);
}

int main(int argc, char *argv[])
{
	pthread_t inctid, lcdtid, seriatid;
	pthread_create(inctid, NULL, incthread, NULL);
	pthread_create(lcdtid, NULL, lcdthread, NULL);
	pthread_create(serialtid, NULL, serialthread, NULL);
	pthread_rwlock_init(&rw1);
	pthread_join(inctid, NULL);
	pthread_join(lcdtid, NULL);
	pthread_join(serialtid, NULL);
	pthread_destroy(&inctid);
	pthread_destroy(&lcdtid);
	pthread_destroy(&serialtid);
	return 0;
}

