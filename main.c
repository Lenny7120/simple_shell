#include "shell.h"
/**
* main - Execute Shell.
*
* Return: 0.
*/
int main(void)
{
char str[BUFFER_SIZE];
char *read;
do {
printf("$ ");
read = fgets(str, BUFFER_SIZE, stdin);
str[strlen(str) - 1] = '\0';
if (read == NULL) /* if getline fails */
{
if (feof(stdin)) /* test for the eof */
{
printf("\n");
exit(EXIT_FAILURE); /* we recieved an eof */
}
else
{
perror("error while reading the line from stdin");
exit(EXIT_FAILURE);
}
}
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
