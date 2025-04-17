#include "shell.h"
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];
	char *token;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	token = strtok(line, "\t\n");
	if (pid == 0)
	{
		argv[0] = token;
		argv[1] = NULL;
		if (execve(line, argv, environ) == -1)
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
