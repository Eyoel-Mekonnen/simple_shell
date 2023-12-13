#include "main.h"
/***
 * main - check the code
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char *path = getenv("PATH");
	char **ptr, **ptr2;
	char *command_part, *line, *corrected_line;
	size_t size = 0;
	ssize_t get;
	int count_token_number = 0, i, command_executed = 0;

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
		for (i = 0; ptr2[i] != NULL; i++)
			count_token_number++;
		command_part = ptr2[0];
		if (!command_executed)
			execute_command(command_part, ptr, ptr2);
	}
	return (0);
}
