#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIMITER " \t\r\n\a"

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE;
	position = 0;

	char *token;
	char **tokens = malloc(bufsize*sizeof(char*));	//creating memory space for input of strings
	if(tokens == NULL)
	{
		fprintf(stderr,"lsh:Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIMITER);	//splitting token strings from given line of strings

	while(taken! = NULL)
	{
		tokens[position] = token;
		position++;
	
		if(position >= bufsize)			//reallocating memory space
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize*sizeof(char*));
		
			if(tokens == NULL)
			{
				fprintf(stderr,"lsh:Extra Memory allocation failed!\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, LSH_TOK_DELIMITER);
	}
	
	tokens[position] = NULL;			//NULL terminating the list of tokens
	return tokens;	
}
