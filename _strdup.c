#include "ssh.h"

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 * Return: new string
 */
char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * _strlen(str) + 1);
	if (dup)
	{
		for (i = 0; i < _strlen(str); i++)
			dup[i] = str[i];
		dup[i] = '\0';
	}
	return (dup);
}
