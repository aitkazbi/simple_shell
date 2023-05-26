#include "ssh.h"
/**
 * _strncat- concat src & dest
 * @dest: destination
 * @src: source
 * @n: size
 * Return: destination
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr;

	ptr = dest;
	while (dest && *dest)
		dest++;
	while (src && *src && n-- > 0)
		*dest++ = *src++;
	return (ptr);
}
