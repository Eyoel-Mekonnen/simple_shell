#include "header.h"

/**
 * processuserinput - returns true if shell is user input mode
 * @info: struct address
 *
 * Return: 1 if user input mode.
 */
int processuserinput(info_t *info)
{
	int isTerm = isatty(STDIN_FILENO);
	int isValid = info->readfd <= 2;

	return (isTerm && isValid);
}

/**
 * isDelimiter - checks if character is a delimeter
 * @ch: the char to check
 * @count: the delimeter string
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char ch, char *count)
{
	for (; *count != '\0'; count++)
	{
		if (*count == ch)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * characterNum - checks for alphabetic character
 * @num: num character to input.
 * Return: 1 if num is alphabetic.
 */

int characterNum(int num)
{
	return ((num >= 'a' && num <= 'z') || (num >= 'A' && num <= 'Z'));
}
