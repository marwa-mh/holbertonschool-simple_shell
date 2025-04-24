#include "shell.h"

/**
 * main - The entry point of the shell.
 *
 * Return: Exit status
 */
int main(void)
{
	char *line;
	int status = 0;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			display_prompt();

		line = read_input();
		if (line == NULL) /* Ctrl+D or error */
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[0] != '\0') /* Skip empty lines */
			status = execute_command(line);

		free(line);
	}

	return (status);
}
