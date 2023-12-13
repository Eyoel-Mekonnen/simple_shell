#include "main.h"
/**
 * custom_setenv - wrapper function for setenv.
 * @ptr2: the token of input passed
 *
 */
void custom_setenv(char **ptr2)
{
	int i, argument_count = 0, overwrite = 1, result;

	for (i = 0; ptr2[i] != NULL; i++)
		argument_count++;
	if (argument_count != 3)
	{
		printf("Usage: setenv VARIABLE_NAME VARIABLE_VALUE\n");
		return;
	}
	result = setenv(ptr2[1], ptr2[2], overwrite);
	if (result != 0)
		printf("Error setting Environment Variable\n");
}
