#include "shell.h"
/**
* interactive - run interactive mode
*
* Return: void
*/

void interactive(void)
{
char *termArgs;
char **argument;
int status = -1;

do {
printf("($) ");
termArgs = readline();
argument = splitTerminalArgs(termArgs);
status = executeArgs(argument);
free(termArgs);
free(argument);
if (status >= 0)
{
exit(status);
}
} while (status == -1);
}
