#include "shell.h"

/**
 * execute_command - Function entry
 * @args: Any argyments to be run with the input.
 * @input: The command to run.
 *
 * Description: Creats a forked process with the give command,
 *							runs it, and then returns back to the main process.
 */
void execute_command(char **args, char *input) {
	int status;
	pid_t child_id = 0;

	if (access(args[0], X_OK) != 0) {
		fprintf(stderr, "./hsh: 1: %s not found\n", args[0]);
		perror("");
		free(args[0]);
		exit(EXIT_FAILURE);
	}

	child_id = fork();

	if (child_id == -1) {
		perror("Failed to fork child process\n");
		free(input);
		free(args[0]);
		exit(EXIT_FAILURE);
	} else if (child_id == 0 && execve(args[0], args, environ) == -1) {
		perror("Failed to run command.");
		exit(EXIT_FAILURE);
	} else {
		wait(&status);
	}	
}

/**
 * handle_path - Function entry
 * @input: The command to search for.
 *
 * Description: Searches through the environment paths to check
 *							if the command exists in those folders.
 *
 * Return: The path if found or NULL
 */
char *handle_path(char *input)
{
	int i;
	char *tmp;
	char *token;
	char *path;

	if (strchr(input, '/') != NULL)
		return (strdup(input));

	for (i = 0; environ[i] != NULL; i++)
	{
		tmp = strdup(environ[i]);
		token = strtok(tmp, "=");
		if (strcmp(token, "PATH") == 0) {
			token = strtok(NULL, "=");
			token = strtok(token, ":");

			while (token != NULL) {
				path = malloc(strlen(token) + strlen(input) + 2);
				if (path == NULL) {
					perror("Malloc is NULL");
					return (NULL);
				}
	
				sprintf(path, "%s/%s", token, input);
				if (access(path, X_OK) == 0) {
					free(tmp);
					return (path);
				}

				free(path);
				token = strtok(NULL, ":");
			}
		}
		free(tmp);
	}

	free(input);
	return (NULL);
}

/**
 * print_env - Function entry
 * Description: Prints the current environment variables.
 */
void print_env(void) {
	char **env;

	for (env = environ; *env != NULL; env++)
		printf("%s\n", *env);
}

/**
 * parse - Function entry
 * @input: The command that will be used.
 * @args: Any arguments to be passed along with the command.
 *
 * Description: Parses the input string and calls the correct
 *							command. Built in commands are ran first, and
 *							then any existing global commands.
 */
void parse(char *input)
{
	char *token;
	int i = 0;
	char *args[64];

	token = strtok(input, " ");
	while (token != NULL) {
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] == NULL)
		exit(0);

	if (strcmp(input, "exit") == 0 && args[1] == NULL) {
		free(args[0]);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(input, "env") == 0) {
		print_env();
		return;
	}

	token = strdup(args[0]);
	args[0] = handle_path(args[0]);
	if (args[0] != NULL) {
		free(token);
		execute_command(args, input);
		free(args[0]);
		return;
	}

	fprintf(stderr, "./hsh: 1: %s: not found\n", token);
	free(token);
	exit(127);
}

