#include "shell.h"
/**
 * executeArgs - execute custom and process commands
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */

typedef int (*BuiltinFunc)(char **);
struct BuiltinCommand
{
    char *name;
    BuiltinFunc func;
};

int executeArgs(char **args)
{
    char *builtin_func_list[] = {"cd", "env", "help", "exit"};
    struct BuiltinCommand builtin_commands[] = {
        {"cd", custom_cd},
        {"env", custom_env},
        {"help", custom_help},
        {"exit", custom_exit}};
    long unsigned int i;
    size_t num_builtin_funcs = sizeof(builtin_func_list) / sizeof(char *);

    if (args[0] == NULL)
    {
        return (-1);
    }
    for (i = 0; i < num_builtin_funcs; i++)
    {
        if (strcmp(args[0], builtin_commands[i].name) == 0)
        {
            return ((*builtin_commands[i].func)(args));
        }
    }
    return (set_new_process(args));
}
