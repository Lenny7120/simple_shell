#include "shell.h"
/**
* executeArgs - execute custom and process commands
* @args: command and its flags
*
* Return: 1 on sucess, 0 otherwise
*/

int executeArgs(char **args, char *arg)
{
char *builtin_func_list[] = {"cd", "env", "help", "exit"};
int (*builtin_func[])(char **) = {
&custom_cd,
&custom_env,
&custom_help,
&custom_exit
};
unsigned long int i;
size_t num_builtin_funcs = sizeof(builtin_func_list) / sizeof(char *);

if (args[0] == NULL)
{
return (-1);
}
for (i = 0; i < num_builtin_funcs; i++)
{
if (strcmp(args[0], builtin_func_list[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
return (set_new_process(args, arg));
}
