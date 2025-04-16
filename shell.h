#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
extern char **environ;
void display_prompt(void);
char *read_input(void);
void execute_command(char *line);
#endif
