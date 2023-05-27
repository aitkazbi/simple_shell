#include "ssh.h"

/**
 * putsExitError - puts error
 * @data :data
 */
void putsExitError(t_data *data)
{
	_puts(data->progName, STDERR_FILENO);
	_puts(": ", STDERR_FILENO);
	_putnbr(data->count_exec, true, STDERR_FILENO);
	_puts(": exit: Illegal number: ", STDERR_FILENO);
	_puts(data->arg[1], STDERR_FILENO);
	_puts("\n", STDERR_FILENO);
}

/**
 * ft_exit - exit
 * @dt: struct for the program's dt
 * Return: Return
 */
int ft_exit(t_data *dt)
{
	int i;
	/*errno = 0;*/

	if (dt->arg[1])
	{
		for (i = 0; dt->arg[1][i]; i++)
			if ((dt->arg[1][i] < '0' || dt->arg[1][i] > '9') && dt->arg[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(dt->arg[1]);
	}
	free_all(dt, false, false);
	exit(errno);
}
