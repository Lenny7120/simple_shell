#include "shell.h"
/**
 * splitTerminalArgs - split the arguments based on different delimiters
 * @termArgs: arguments passed
 *
 * Return: Array of strings
 */

char **splitTerminalArgs(char *termArgs)
{
    int bufsize = 64;
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "allocation error in splitTerminalArgs: tokens\n");
        exit(1);
    }
    token = strtok(termArgs, TOKEN_DELIM);
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += bufsize;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "reallocation error in splitTerminalArgs: tokens");
                exit(1);
            }
        }
        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[i] = NULL;
    return (tokens);
}
