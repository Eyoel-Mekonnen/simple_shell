#include "shell.h"
#include <unistd.h>
/**
 * execute_command - searches for a command and execute it
 * @command_part: the string of the commmand passed
 * @ptr: the pointer to array of path created per directory
 * @ptr2: the token passed
 *
 */
void execute_command(char *command_part, char **ptr, char **ptr2)
{
	char **argv, **envp, **argv2, **envp2;
	char *path_part, *appended = NULL;
	struct stat filestat;
	pid_t child1;
	int i, status;

	for (i = 0; ptr[i] != NULL; i++)
	{
		path_part = ptr[i];
		appended = appender(path_part, command_part);
		if (command_part[0] == '/')
		{
			path_part = "";
			appended = command_part;
		}
		else
		{
			path_part = ptr[i];
			appended = appender(path_part, command_part);
		}
		if (stat(appended, &filestat) == 0)
		{
			child1 = fork();
			if (child1 == -1)
			{
				perror("Fork");
			}
			else if (child1 == 0)
			{
				argv = argv1(appended, ptr2);
				envp = envp1(appended);
				argv2 = argv;
				envp2 = envp;
				free(appended);/**freed**/
				free_strtow(argv);/**write function**/
				free_strtow(envp); /**wrte function**/
				execve(argv2[0], argv2, envp2);
				perror("Execve");
				exit(EXIT_FAILURE);
			}
			else
			{

				
				wait(&status);
				break;
			}
		}
		if (ptr[i + 1] == NULL)
			perror(" :Command Not Found");
		if (command_part[0] != '/')
		{
			free(appended);
		}
	}
}
