#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

#include"shm_header.h"

int main(int argc, char *argv[])
{
	void *memory = NULL;
	struct sh_struct *sh_data;
	int shmid;

	if((shmid = shmget((key_t)5678, sizeof(struct sh_struct), 0666|IPC_CREAT)) == -1)
	{
		fprintf(stderr,"shmget failed\n");
		exit(EXIT_FAILURE);
	}

	if((memory = shmat(shmid, NULL, 0)) == (void *)-1)
	{
		fprintf(stderr,"shmgat failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Memory attached at %p\n",memory);

	sh_data = (struct sh_struct*)memory;
	sh_data->written = 0;
	
	while(1)
	{
		if(sh_data->written)
		{
			printf("Message received:%s",sh_data->text);
			sleep(1);
			sh_data->written = 0;
			if(strncmp(sh_data->text, "end", 3) == 0)
				exit(1);
		}
	}

	if(shmdt(memory) == -1)
	{
		fprintf(stderr,"shmdt failed\n");
		exit(EXIT_FAILURE);
	}

	if(shmctl(shmid, IPC_RMID, 0) == -1)
	{
		fprintf(stderr,"shmctl remove failed\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
