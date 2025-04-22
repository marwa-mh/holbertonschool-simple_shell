#include "shell.h"

extern char **environ;

/**
 * _getenv - Get the envrionment variables
 * @name: The path to read from
 *
 * Return: The list of paths
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		 	return &environ[i][len + 1];

		i++;
	}
	return (NULL);
}


/**
 * find_in_path - Searches for a command in PATH
 * @command: Command to search
 *
 * Return: PATH to command if found and executable, or NULL if not found
 */
char *find_in_path(const char *command)
{
    char *path = _getenv("PATH");
    char *path_copy;
    char *dir = strtok(path_copy, ":");
    char full_path[1024];

	if (path == NULL || *path == '\0')
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

  while (dir != NULL)
  {
		full_path[0] = '\0';

    strcpy(full_path, dir);
    strcat(full_path, "/");
    strcat(full_path, command);

    if (access(full_path, X_OK) == 0)
    {
      free(path_copy);
				return strdup(full_path);
    }
    dir = strtok(NULL, ":");
  }

  free(path_copy);
  return (NULL);
}
