#include "shell.h"
/**
* execute_argument - Execute a given argument.
*
* @argument: The argument to execute.
* Return: void
*/
void execute_argument(char *argument)
{
<<<<<<< HEAD
pid_t p = fork();
char *executable, *path, *full_argument, *token;
char *env[] = {NULL};
int i = 0;

if (p == -1)
{
perror("Forking failed");
}
else if (p == 0)
{
char *args[64];
token = strtok(argument, TOK_DELIM);
while (token != NULL)
{
if (token[0] == '#')
{
break;
}
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
executable = args[0];
path = "/bin/";
full_argument = malloc(strlen(path) + strlen(executable) + 1);
if (full_argument == NULL)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}
strcpy(full_argument, path);
strcat(full_argument, executable);
if (execve(full_argument, args, env) == -1)
{
perror("argument execution failed");
exit(EXIT_FAILURE);
}
free(full_argument);
}
else
{
int status;
waitpid(p, &status, 0);
}
}
=======
    pid_t p = fork();
    char *tokens[64];
    char *exe, *path, *full_argument, *token;
    char *env[] = {NULL};
    int i = 0;

    if (p == -1)
    {
        perror("Forking failed");
    }
    else if (p == 0)
    {
        token = strtok(argument, TOK_DELIM);
        while (token != NULL)
        {
            if (token[0] == '#')
            {
                break;
            }
            tokens[i++] = token;
            token = strtok(NULL, TOK_DELIM);
        }
        tokens[i] = NULL;
        exe = tokens[0];
        path = "/bin/";
        full_argument = malloc(strlen(path) + strlen(exe) + 1);
        if (full_argument == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        strcpy(full_argument, path);
        strcat(full_argument, exe);
        if (execve(full_argument, tokens, env) == -1)
        {
            perror("argument execution failed");
            exit(EXIT_FAILURE);
        }
        free(full_argument);
    }
    else
    {
        int status;
        waitpid(p, &status, 0);
    }
}
>>>>>>> b9e13dc9d3a1f6e21d0f57da5a6dffafe0c786cd
