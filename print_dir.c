#include "shell.h"
/**
 * displayCurrentDirectory - print working directory
 *
 * Return: void
 */
void displayCurrentDirectory(void)
{
    char *buffer;
    long size;

    size = pathconf(".", _PC_PATH_MAX);

    if ((buffer = (char *)malloc((size_t)size)) != NULL)
    {
        if (getcwd(buffer, (size_t)size) != NULL)
        {
            printf("%s: ", buffer);
        }
        else
        {
            perror("getcwd");
        }

        free(buffer);
    }
    else
    {
        perror("malloc");
    }
}