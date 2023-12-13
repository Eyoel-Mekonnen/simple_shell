#include "main.h"
/**
 * custom_env - prints environment using environ.
 * @ptr2: the token passed
 *
 */
void custom_env(char **ptr2 __attribute__((unused)))
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
