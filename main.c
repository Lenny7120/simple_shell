#include "shell.h"
/**
* main - run a simple shell
*
* Return: 0
*/

int main(int argc, char *args[])
{
(void)argc;	

if (isatty(STDIN_FILENO) == 0)
{
interactive(args[0]);
}
else
{
not_interactive(args[0]);
}
return (0);
}
