#include "main.h"
/**
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

	ptr = strtow_path(path);
	while (1)
	{
		printf("($) ");
		get = getline(&line, &size, stdin);
		if (get == -1 || get == EOF)
		{
			printf("\n");
			exit(EXIT_FAILURE);
		}
		if (line == NULL || line[0] == '\n' || line[0] == ' ')
			continue;
		corrected_line = line_corrected(line);
		ptr2 = strtow(corrected_line);
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
			execute_command(command_part, ptr, ptr2);
	}
	return (0);
}
