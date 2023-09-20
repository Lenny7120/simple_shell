#include "shell.h"
/**
* main - run a simple shell
*
* Return: 0
*/

int main(void)
{
if (isatty(STDIN_FILENO) == 1)
{
interactive();
}
else
{
not_interactive();
}
return (0);
}
