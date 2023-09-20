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

    return (line);
}
