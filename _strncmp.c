#include "ssh.h"
/**
 * _strncmp- cmp src & dest
 * @s1: s1
 * @s2: s2
 * @n: n
 * Return: int
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	if (!s1 && !s2)
		return (1);

	if (!s1 || !s2)
		return (0);

	if (!n)
	{
		if (_strlen(s1) != _strlen(s2))
			return (0);
		for (i = 0; s1[i]; i++)
		{
			if (s1[i] != s2[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < n ; i++)
		{
			if (s1[i] != s2[i])
			return (0);
		}
		return (1);
	}
}
