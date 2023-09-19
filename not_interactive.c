#include "shell.h"
/**
* not_interactive - run non-interactive mode
*
* Return: void
*/
void not_interactive(char *arg)
{
char *line;
char **args;
int status = -1;

do {
printf("($) ");
line = read_stream();
args = splitTerminalArgs(line);
status = executeArgs(args, arg);
free(line);
free(args);
if (status >= 0)
{
exit(status);
}
} while (status == -1);
}
