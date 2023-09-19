#include "shell.h"
/**
* interactive - run interactive mode
*
* Return: void
*/

void interactive(char *arg)
{
char *termArgs;
char **argument;
int status = -1;

do {
printf("($) ");
termArgs = readline();
argument = splitTerminalArgs(termArgs);
status = executeArgs(argument, arg);
free(termArgs);
free(argument);
if (status >= 0)
{
exit(status);
}
} while (status == -1);
}
