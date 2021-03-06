int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

char *builtin_str[]
{
	"cd"
	"help"
	"exit"
};

int (*builtin_func[])(char**) =
{
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};
int lsh_num_builtin()
{
	return sizeof(builtin_str)/sizeof(char*);
}

int lsh_cd(char **args)
{
	if(args[1] == NULL)
		fprintf(stderr,"lsh:expected arguement to \"cd\"\n");
	else
	{
		if(chdir(args[1])!= 0)
			perror("lsh");
	}
	return 1;
}

int lsh_help(char **args)
{
	int i;
	printf("Welcome to the LSH Help Centre\n");
	printf("Type program name and arguements:\n");
	printf("Following contents are Built-in:\n");
	
	for(i=0;i<lsh_num_builtin();i++)
		printf(" %s\n",builtin_str[i]);
	printf("Use the man command for supports other than this.\n");
	return 1;
}			

int lsh_exit(char **args)
{
	return 0;
}
