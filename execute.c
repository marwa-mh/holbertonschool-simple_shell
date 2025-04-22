#include "shell.h"
/**
 * execute_command - Branches valid arguments into its own process
 * @line: The line to parse
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[64];
	char *token, *full_path;
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

	/* Check if command has a '/' or needs PATH resolution */
	if (strchr(argv[0], '/'))
	{
		full_path = argv[0];
	}
	else
	{
		full_path = find_in_path(argv[0]);
		if (!full_path)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			return;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		return;
	}

	if (pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (full_path != argv[0])
			free(full_path);
	}
}
