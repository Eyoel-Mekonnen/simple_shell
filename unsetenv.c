#include "shell.h"
/**
 * remover - removes a variable
 * @environ: the pointer of environ
 * @environ2: the pointer that will have the copy of environ
 * @tracker: index which the environ will be removed
 *
 * Retrun: Address of environ2
 */
char **remover(char ** environ, char **environ2, int tracker)
{
	char *string;
	int i, j, k = 0, count;

	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;
		count = 0;
		if (tracker == i)
		{
			continue;
		}
		else
		{
			string = environ[i];
		}
		while (string[count] != '\0')
			count++;
		*(environ2 + k) = malloc(sizeof(char) * (count + 1));
		if (environ2[k] == NULL)
		{
			free_strtow(environ2);
			return (NULL);
		}
		for (j = 0; j < count; j++)
		{
			*(*(environ2 + k) + j) = string[j];
		}
		*(*(environ2 + k) + j) = '\0';
		k++;
	}
	*(environ2 + k) = '\0';
	for (i = 0; environ[i] != NULL; i++)
	{
		free(environ[i]);
	}
	free(environ);
	return (environ2);
}
/**
 * _unsetenv - deletes a variable from the environment
 * @name: name of the environment you want to delete
 *
 * Return: 1 on Success
 */
int _unsetenv(const char *name)
{
	extern char **environ;
	char **environ2;
	int i, tracker = 0, count_environ = 0, valued;

	while (environ[count_environ] != NULL)
		count_environ++;
	for (i = 0; *(environ + i) != NULL; i++)
	{
		valued = _strcmp(environ[i], name);
		if (valued == 0)
		{
			tracker = i;
			environ2 = malloc(sizeof(char *) * count_environ);
			if (environ2 == NULL)
				return (-1);
			environ = remover(environ, environ2, tracker);
			break;
		}
		else if (valued != 0)
			continue;
	}
	return (0);
}
