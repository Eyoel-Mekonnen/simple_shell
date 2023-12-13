#include "main.h"
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
	char *path_part, *appended;
	struct stat filestat;
	pid_t child1;
	int i, status;

	for (i = 0; ptr[i] != NULL; i++)
	{
		path_part = ptr[i];
		appended = appender(path_part, command_part);
		if (command_part[0] == '/')
		{
			appended = command_part;
		}
		else if (command_part[0] != '/')
		{
			perror("./hsh: No such file or directory");
			return;
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
				execve(argv[0], argv, envp);
			}
			else
			{

				wait(&status);
				break;
			}
		}
		if (ptr[i + 1] == NULL)
			perror(" :Command Not Found");
	}
}
