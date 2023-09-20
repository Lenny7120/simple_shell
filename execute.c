#include "shell.h"
/**
* execute_argument - Execute argument passed
* @argument: argument.
* Return: void
*/
void execute_argument(char *argument)
{
pid_t p = fork();
char *tokens[64];
char *exe, *path, *memory, *token;
char *env[] = {NULL};
int i = 0;
int status;

if (p == -1)
	perror("Forking failed");
else if (p == 0)
{
token = strtok(argument, TOK_DELIM);
while (token != NULL)
{
tokens[i++] = token;
token = strtok(NULL, TOK_DELIM);
}
tokens[i] = NULL;
exe = tokens[0];
path = "/bin/";
memory = malloc(strlen(path) + strlen(exe) + 1);
if (memory == NULL)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}
strcpy(memory, path);
strcat(memory, exe);
if (execve(memory, tokens, env) == -1)
{
perror("argument execution failed");
exit(EXIT_FAILURE);
}
free(memory);
}
waitpid(p, &status, 0);
}

