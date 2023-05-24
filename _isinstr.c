#include "ssh.h"
/**
 * _isinstr- return true if Is in string
 * @str: string
 * @toFind : char to find in str
 * Return: true if is find
 */

int _isinstr(char *str, char toFind)
{
	while (*str)
	{
		if (*str == toFind)
			return (1);
		str++;
	}
	return (0);
}
