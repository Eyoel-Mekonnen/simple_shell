#include "shell.h"

/***
 * main - check the code
 *
 * Return: Always 0 on success
 */

int main(void)
{
	cmd custom_commands[] = {{"exit", custom_exit}, {"env", custom_env}, 
		{"setenv", custom_setenv}, 
		{"unsetenv", custom_unsetenv}, {"cd", custom_cd}};
	char *path = getenv("PATH");
	char **ptr, **ptr2;
	char *command_part, *line, *corrected_line;
	size_t size = 0;
	ssize_t get;
	int count_token_number = 0, i, value, command_executed = 0;

	line = NULL;
	ptr = strtow_path(path);
	while (1)
	{
	 	if (isatty(STDIN_FILENO))
            		printf("#cisfun$ ");
		get = getline(&line, &size, stdin);
		if (get == -1)
		{	
			free(line);
			free_strtow(ptr);
			exit(EXIT_SUCCESS);
		}
		if (line == NULL || line[0] == '\n' || line[0] == ' ')
		{
			free(line);
			line = NULL;
			continue;
		}
		corrected_line = line_corrected(line);
		ptr2 = strtow(corrected_line);
		free(corrected_line);
		for (i = 0; ptr2[i] != NULL; i++)
			count_token_number++;
		command_part = ptr2[0];
		for (i = 0; i < 5; i++)
		{
			value = _strcmp1(command_part, custom_commands[i].command);
			if (value == 0)
			{
				custom_commands[i].func(ptr2);
				command_executed = 1;
				break;
			}

		}
		if (!command_executed)
		{
			execute_command(command_part, ptr, ptr2);
			free_strtow(ptr2);
		}
		free_strtow(ptr2);
		free(line);
		line = NULL;
	}
	free_strtow(ptr);
	return (0);
}
