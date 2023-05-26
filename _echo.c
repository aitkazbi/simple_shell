#include "ssh.h"

/**
 * to_string - to_string
 * @n: n
 * @i: i
 * Return: string length
 */
int to_string(int i, unsigned int n)
{
	char digit;

	if (n >= 10)
		return (to_string(i, n / 10) + to_string(i, n % 10));
	digit = '0' + n;
	if (i == 1)
		return (write(STDOUT_FILENO, &digit, 1));
	return (write(STDERR_FILENO, &digit, 1));
}

/**
 * _echo - echo $$ and $?
 * @arg: arg
 * Return: success
 */
int _echo(char *arg)
{
	int status;

	if (!_strcmp(arg, "$?"))
	{
		waitpid(getpid() - 1, &status, 0);
		to_string(1, WEXITSTATUS(status));
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	else if (!_strcmp(arg, "$$"))
	{
		to_string(1, getpid());
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}
