#include "main.h"
/**
 * _strcmp1 - compares two strings
 * @s1: the string that passed
 * @s2: the second string that is passed
 *
 * Return: 0 if they are equal
 */
int _strcmp1(char *s1, char *s2)
{
	int len = 0, len2 = 0, i, value = 0;

	while (s1[len] != '\0')
		len++;
	while (s2[len2] != '\0')
		len2++;
	for (i = 0; i < len; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		else if (s1[i] != s2[i])
		{
			value = (s1[i] + 48) - (s2[i] + 48);
			break;
		}
	}
	return (value);
}
