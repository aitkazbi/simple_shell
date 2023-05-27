#include "ssh.h"
/**
 * _strconcat - _strconcat.
 * @s1: s1
 * @s2: s2
 *
 * Return: pointer to the array
 */
char *_strconcat(char *s1, char *s2)
{
	char *result;
	int len1 = 0, len2 = 0;

	if (!s1)
		s1 = "";
	len1 = _strlen(s1);

	if (!s2)
		s2 = "";
	len2 = _strlen(s2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (len1 = 0; s1[len1] != '\0'; len1++)
		result[len1] = s1[len1];
	free(s1);

	for (len2 = 0; s2[len2] != '\0'; len2++)
	{
		result[len1] = s2[len2];
		len1++;
	}

	result[len1] = '\0';
	return (result);
}
