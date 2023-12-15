#include "header.h"
/**
 * custom - converts a string to integer.
 * @input: string to be converted.
 * Return: 0 if no numbers in string.
 */

int custom(const char *input)
{
	int ij, x = 1, y = 0, output;
	unsigned int counter;

	counter = 0;

	for (ij = 0; input[ij] != '\0' && y != 2; ij++)
	{
		if (input[ij] == '-')
			x *= -1;
		if (input[ij] >= '0' && input[ij] <= '9')
		{
			y = 1;
			counter *= 10;
			counter += (input[ij] - '0');
		}
		else if (y == 1)
			y = 2;
	}
	if (x == -1)
	{
		output = -counter;
	}
	else
	{
		output = counter;
	}
	return (output);
}
