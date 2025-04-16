#include "shell.h"
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL); /* Handles EOF (Ctrl+D) or error */
	}

	/* Remove newline at the end */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
