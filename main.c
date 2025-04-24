#include "shell.h"

/**
 * main - The entry point of the shell.
 *
 * Return: Always 1
 */
int main(void)
{
	char *input = NULL;

	// Uncomment to set the PATH variable to blank.
	// setenv("PATH", "", 1);

	while (1)
	{
		display_prompt();

		input = read_input();
		if (input == NULL) {
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (input[0] != '\0')
			parse(input);
	}
	free(input);
	return (0);
}
