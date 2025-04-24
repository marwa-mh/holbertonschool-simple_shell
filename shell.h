#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

extern char **environ;
void print_error(char *args[]);

void execute_command(char **args, char *input);
void parse(char *input);
char *handle_path(char *input);
int check_spaces(char *str);

void display_prompt();
char *read_input();

#endif
