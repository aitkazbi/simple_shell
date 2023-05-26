#include "ssh.h"
/**
 * _strcmp- cmp src & dest
 * @s1: s1
 * @s2: s2
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	while (s1 && *s1 && s2 && *s1++ == *s2++)
		;
	return (*(s1 - 1) - *(s2 - 1));
}
