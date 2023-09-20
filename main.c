#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void execute_command(const char *command);

/**
 * main - Entry point of the shell program.
 *
 * Description: Reads user input, executes commands, and exits o"exit" command.
 *
 * Return: Always returns 0.
 */
int main(void)
{
    char input[BUFFER_SIZE];

    while (1)
    {
        /* prints the prompt */
        printf("$ ");
        /* basically my getline */
        fgets(input, BUFFER_SIZE, stdin);

        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting the shell...\n");
            break;
        }

        execute_command(input);
    }

    return (0);
}

/**
 * execute_command - Execute a given command.
 *
 * @command: The command to execute.
 *
 * Description: Forks a child process to execute the commandand waits for it to
 * complete.
 */
void execute_command(const char *command)
{
    pid_t pid = fork();
    char *executable, *full_path, *full_command;
    char *env[] = {NULL};

    if (pid == -1)
    {
        perror("Fork failed");
    }
    else if (pid == 0)
    {
        /* child process*/
        char *args[64];
        char *token = strtok((char *)command, " ");
        int i = 0;

        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        /* Specify the full path to the executable */
        executable = args[0];
        full_path = "/bin/"; /* Adjust this path as needed */
        full_command =
            malloc(strlen(full_path) + strlen(executable) + 1);
        if (full_command == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        strcpy(full_command, full_path);
        strcat(full_command, executable);

        /* Prepare environment variables (optional) */

        if (execve(full_command, args, env) == -1)
        {
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }

        free(full_command);
    }
    else
    {
        /* Parent process */
        int status;

        waitpid(pid, &status, 0);
    }
}