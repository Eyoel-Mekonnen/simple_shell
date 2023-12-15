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
	char **argv, **envp;
	char *path_part, *appended = NULL;
	struct stat filestat;
	pid_t child1;
	int i, status;

	argv = NULL;
	envp = NULL;
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
			if (appended == NULL)
			{
				perror("Memory allocation failed for appended");
				break;
			}
		}
		if (stat(appended, &filestat) == 0)
		{
			child1 = fork();
			if (child1 == -1)
			{
				perror("Fork");
				if (command_part[0] != '/')
				{
					free(appended);
					break;
				}
				
			}
			else if (child1 == 0)
			{
				argv = argv1(appended, ptr2);
				envp = envp1(appended);
				if (command_part[0] != '/')
					free(appended);
				execve(argv[0], argv, envp);
				perror("Execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				
				wait(&status);
				if (argv)
					free_strtow(argv);
				if (envp)
					free_strtow(envp);
				if (command_part[0] != '/')
					free(appended);
				break;
			}
		}
		else
		{
			if (command_part[0] != '/' && appended != command_part)
				free(appended);
		}
		if (ptr[i + 1] == NULL)
		{
			perror(" :Command Not Found");
		}
		
	}
}
