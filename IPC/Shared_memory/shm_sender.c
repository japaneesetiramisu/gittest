#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

#include"shm_header.h"

#define BUFSIZE 200

int main(int argc, char *argv[])
{
	void *memory = NULL;
	struct sh_struct *sh_data;
	char buffer[BUFSIZE];
	int shmid;

if((shmid = shmget((key_t)5678, sizeof(struct sh_struct), 0666|IPC_CREAT)) == -1)
	{
		fprintf(stderr,"shmget failed\n");
		exit(EXIT_FAILURE);
	}

	if((memory = shmat(shmid, NULL, 0)) ==(void *)-1)
	{
		fprintf(stderr,"shmgat failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Memory attached at %p\n",memory);

	sh_data = (struct sh_struct*)memory;
	
	while(1)
	{
		while(sh_data->written == 1)
		{
			printf("Message received:%s",sh_data->text);
			sleep(1);
			printf("Waiting for client...\n");
		}
		printf("Enter Message:\n");
		fgets(buffer, BUFSIZE, stdin);
		
		strncpy(sh_data->text, buffer, TEXT_SIZE);
		sh_data->written = 1;

		if(strncpy(buffer, "end", 3) == 0)
			exit(1);
	}

	if(shmdt(memory) == -1)
	{
		fprintf(stderr,"shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
