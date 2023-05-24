#include "ssh.h"

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 * Return: new string
 */
char *_strdup(char *str)
{
	char *dup;
	size_t i;

	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * strlen(str) + 1);
	if (dup != NULL)
	{
		for (i = 0; i < strlen(str); i++)
			dup[i] = str[i];
	}
	dup[i] = '\0';
	return (dup);
}
