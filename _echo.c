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
int _echo(char **arg)
{
	int status;
	int i = 1;

	if (arg[1] && !_strcmp(arg[1], "$?"))
	{
		waitpid(getpid() - 1, &status, 0);
		_putnbr(WEXITSTATUS(status), true, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	else if (arg[1] && !_strcmp(arg[1], "$$"))
	{
		_putnbr(getpid(), true, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	else
	{
		while (arg[i])
		{
			_puts(arg[i++], STDOUT_FILENO);
			if (arg[i])
				_putchar(' ', STDOUT_FILENO);
		}
		_putchar('\n', STDOUT_FILENO);
		return (1);
	}
	return (0);
}

