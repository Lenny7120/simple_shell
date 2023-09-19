#include "shell.h"
/**
* readline - read arguments entered in shell
*
* Return: string
*/

char *readline(void)
{
char *line;
size_t bufsize = 0;
int read = getline(&line, &bufsize, stdin);

if (read == -1)
{
if (feof(stdin))
{
free(line);
exit(0);
}
else
{
free(line);
perror("error");
exit(1);
}
}
return (line);
}
