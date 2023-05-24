#include "unistd.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @fd: fd
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * _puts- puts
 * @str: str
 * @fd: fd
 */
void _puts(char *str, int fd)
{
	while (*str != '\0')
	{
		_putchar(*str, fd);
		str++;
	}
}
