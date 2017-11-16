#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf{
	long msgtype;
	char msgtext[200];
	};
int main(int argc, char *argv[])
{
	struct msgbuf msg;
	key_t key;
	int msgid;

	if((key=ftok("msg_snd.c",'b'))==-1)
	{
		perror("key");
		exit(EXIT_FAILURE);
	}
	
	if((msgid=msgget(key, 0644))==-1)
	{
		perror("msgid");
		exit(EXIT_FAILURE);
	}
	printf("Received Message:\n");
	msg.msgtype =1;

	for(;;)
	{
		if((msgrcv(msgid, &msg, sizeof(msg), 1, 0)) == -1)
		{
			perror("msgrcv");
			exit(EXIT_FAILURE);
		}
		printf("%s\n",msg.msgtext);
	}

	exit(EXIT_SUCCESS);
}
