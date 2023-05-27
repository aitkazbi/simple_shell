#include "ssh.h"
/**
 * str_dup- str_dup
 * @str: str
 * Return: pointer to str
 */
char *str_dup(char *str)
{
	char *strRes;
	int length, i;

	if (str == NULL)
		return (NULL);

	length = _strlen(str) + 1;
	strRes = malloc(sizeof(char) * length);
	if (strRes == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		strRes[i] = str[i];
	}
	return (strRes);
}
