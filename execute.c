#include "shell.h"
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[64];
	char *token;
	int i = 0;

	token = strtok(line, " \t\n");
	if (token == NULL)
		return;
	while (token != NULL && i < 63)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
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
