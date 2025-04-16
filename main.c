#include "shell.h"
int main(void)
{
	char *line;

	while (1)
	{
		display_prompt();

		line = read_input();
		if (line == NULL) /* Ctrl+D or error */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[0] != '\0') /* Skip empty lines */
			execute_command(line);

		free(line);
	}
	return (0);
}
