#include "ssh.h"
/**
 * _putnbr - print or len number.
 * @a: integer
 * @isToPut : isToPut
 * @fd: fd
 * Return: nb char of n
 */
int _putnbr(unsigned long int a, bool isToPut, int fd)
{
	int len = 0;

	if (a / 10)
		len += _putnbr(a / 10, isToPut, fd);
	len += isToPut ? _putchar(a % 10 + '0', fd) : 1;
	return (len);
}
