#include "shell.h"
/**
 * envp1 - creates the enviornment variable
 * @appended: appended
 *
 * Return: address of created Enviornment
 */
char **envp1(char *appended)
{
	char *envgetter, *string;
	char **envp;
	int count = 0, count_appended = 0, i, j;

	envgetter = getenv("HOME");
	while (appended[count_appended] != '\0')
		count_appended++;
	envp = malloc(sizeof(char *) * 3);
	for (i = 0; i < 2; i++)
	{
		j = 0;
		count = 0;
		if (i == 0)
		{
			string = appended;
		}
		else if (i == 1)
		{
			string = envgetter;
		}
		while (string[count] != '\0')
		{
			count++;
		}
		*(envp + i) = malloc(sizeof(char) * (count + 1));
		for (j = 0; j < count; j++)
		{
			*(*(envp + i) + j) = string[j];
		}
		*(*(envp + i) + j) = '\0';
	}
	*(envp + i) = NULL;
	return (envp);
}
