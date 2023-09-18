#include "shell.h"

/**
 * custom_exit - couses normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int custom_exit(char **args)
{
    if (args[1])
    {
        return (atoi(args[1]));
    }
    else
    {
        return (0);
    }
}
