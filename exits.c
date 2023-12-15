#include "header.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int xx, yy;
	char *s = dest;

	xx = 0;
	while (src[xx] != '\0' && xx < n - 1)
	{
		dest[xx] = src[xx];
		xx++;
	}
	if (xx < n)
	{
		yy = xx;
		while (yy < n)
		{
			dest[yy] = '\0';
			yy++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int inputs, joutputs;
	char *s = dest;

	inputs = 0;
	joutputs = 0;
	while (dest[inputs] != '\0')
		inputs++;
	while (src[joutputs] != '\0' && joutputs < n)
	{
		dest[inputs] = src[joutputs];
		inputs++;
		joutputs++;
	}
	if (joutputs < n)
		dest[inputs] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++ != '\0');
	{
		return (NULL);
	}
}
