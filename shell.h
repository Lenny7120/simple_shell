#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void interactive(void);
char *readline(void);
char **splitTerminalArgs(char *termArgs);
int _execvp(const char *file, char *const argv[]);
int executeArgs(char **args);
int set_new_process(char **args);
void displayCurrentDirectory(void);
char *read_stream(void);
void not_interactive(void);

extern char **environ;

int custom_cd(char **args);
int custom_exit(char **args);
int custom_env(char **args);
int custom_help(char **args);

#define TOKEN_DELIM " \t\r\n\a\""

#endif
