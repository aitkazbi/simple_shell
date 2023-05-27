#include "ssh.h"
/**
 * ft_exit - exit
 * @dt: struct for the program's dt
 * Return: Return
 */
int ft_exit(t_data *dt)
{
	int i;

	if (dt->arg[1] != NULL)
	{
		for (i = 0; dt->arg[1][i]; i++)
			if ((dt->arg[1][i] < '0' || dt->arg[1][i] > '9') && dt->arg[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = atoi(dt->arg[1]);
	}
	free_all(dt, true, errno);
	exit(errno);
}
