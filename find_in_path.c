#include "shell.h"

/**
 * find_in_path - Searches for a command in PATH
 * @command: Command to search
 *
 * Return: PATH to command if found and executable, or NULL if not found
 */
char *find_in_path(const char *command)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char full_path[1024];

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
    return NULL;
}
