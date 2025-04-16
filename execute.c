#include "shell.h"
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		argv[0] = line;
		argv[1] = NULL;
		execve(line, argv, environ);
		perror("./shell"); /* execve failed */
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status); /* Parent waits for child */
	}
}
