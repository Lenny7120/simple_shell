#include "shell.h"
/**
* not_interactive - run non-interactive mode
*
* Return: void
*/
void not_interactive(void)
{
char *line;
char **args;
int status = -1;

do {
displayCurrentDirectory();
line = read_stream();
args = splitTerminalArgs(line);
status = executeArgs(args);
free(line);
free(args);
if (status >= 0)
{
exit(status);
}
} while (status == -1);
}
