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
	
	if((msgid=msgget(key, 0644|IPC_CREAT))==-1)
	{
		perror("msgid");
		exit(EXIT_FAILURE);
	}
	printf("Enter Text(max 200):\n");
	msg.msgtype =1;

	while(gets((msg.msgtext), !feof(stdin)))
	{
		if(msgsnd(msgid, &msg, sizeof(msg),0) == -1)		
		{	
			perror("msgsnd");
			exit(EXIT_FAILURE);
		}
	}

	if(msgctl(msgid, IPC_RMID, NULL) == -1)
	{
		perror("msgctl");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}






/*gcc -o snd sendfile.c
gcc -o rcv receivefile.c*/
