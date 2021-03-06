#define LSH_RL_BUFSIZE 1024

char *lsh_read_line(void)
{
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	int c;

	char *buffer=malloc(sizeof(char)*bufsize);//alocating dynamic memory for line input
	if(buffer == NULL)
	{
		fprintf(stderr,"lsh:Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	
	while(1) 				//taking input. Any EOFs and newlines are replaced with NULL
	{
		c=getchar();
		if(c == EOF || c =='\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position]=c;
		}
		position++;
		
		if(position>=bufsize)		//if the input exceeds allocated memory
		{
			bufsize+ = LSH_RL_BUFSIZE;
			buffer=realloc(buffer, bufsize);
		}
		if(buffer == NULL)
		{
			fprintf(stderr,"lsh:Memory allocation failed!\n");
			exit(EXIT_FAILURE);
		}		
	}

}
