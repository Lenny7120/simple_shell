#include "shell.h"
/**
* main - Execute Shell.
*
* Return: 0.
*/
int main(void)
{
char str[BUFFER_SIZE];

do {
printf("$ ");
fgets(str, BUFFER_SIZE, stdin);
str[strlen(str) - 1] = '\0';
if (strcmp(str, "exit") == 0)
{
	printf("\n");
	break;
}
execute_argument(str);
printf("%s", str);
} while (1);

return (0);
}
