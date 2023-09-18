#include "shell.h"
/**
 * _execvp - execute a program
 * @file: A pointer to a null-terminated string
 * @argv: An array of pointers to null-terminated strings
 *
 * Return: integer
 */

int _execvp(const char *file, char *const argv[])
{
    char *path;
    char *path_copy;
    char *token;
    int result;

    if (strchr(file, '/') != NULL)
    {
        return execve(file, argv, environ);
    }
    path = getenv("PATH");
    if (path == NULL)
    {
        return -1;
    }
    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("strdup");
        return -1;
    }
    token = strtok(path_copy, ":");
    result = -1;
    while (token != NULL)
    {
        char executable_path[1024];
        snprintf(executable_path, sizeof(executable_path), "%s/%s", token, file);
        result = execve(executable_path, argv, environ);
        if (result != -1)
        {
            break;
        }
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return result;
}
