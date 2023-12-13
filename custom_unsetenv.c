#include "shell.h"
/**
 * custom_unsetenv - wrapper function for unsetenv
 * @ptr2: the user input tokenized
 *
 */
void custom_unsetenv(char **ptr2)
{
	int i, argument_count = 0, result;

	for (i = 0; ptr2[i] != NULL; i++)
		argument_count++;
	if (argument_count != 2)
	{
		printf("Usage: unsetenv VARIABLE_NAME\n");
		return;
	}
	result = _unsetenv(ptr2[1]);
	if (result != 0)
		printf("Error unsetting environment variable\n");
}
