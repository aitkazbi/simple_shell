#include "ssh.h"
/**
 * _strncpy- strncpy
 * @dest: destination
 * @src: source
 * @n: size
 * Return: destination
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr;

	ptr = dest;
	while (src && *src && n-- > 0)
		*dest++ = *src++;
	while (n-- > 0)
		*dest++ = '\0';
	return (ptr);
}
