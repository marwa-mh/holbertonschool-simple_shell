#include "shell.h"
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *start, *end;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL); /* Handles EOF (Ctrl+D) or error */
	}

	/* Remove newline at the end */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	start = line;
	while (*start && isspace(*start))
		start++;
	end = start + strlen(start) -1;
	while (end > start && isspace(*end))
		*end-- = '\0';
	char *cleaned = strdup(start);
	free(line);

	return (cleaned);
}
