#include "shell.h"
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];
	char *token;


	token = strtok(line, " \t\n");
	pid = fork();
	argv[0] = token;
	argv[1] = NULL;
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(token, argv, environ) == -1)
		{
			perror("./shell"); /* execve failed */
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status); /* Parent waits for child */
	}
}
