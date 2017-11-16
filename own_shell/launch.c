int lsh_launch(char **args)
{
	pid_t pid, wpid;
	int status;
	pid = fork();

	if(pid==0)
	{
		if(execvp(args[0], args)== -1)
			perror("lsh");
	
		exit(EXIT_FAILURE);
	}
	else if(pid < 0)
		perror("fork failed\n");
	else()
	{
		do{
		wpid = waitpid(pid, &status, WUNTRACED);//returns if a child has stopped untraced
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}
