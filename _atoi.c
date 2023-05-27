#include "ssh.h"
/**
 * _atoi- atoi
 * @str: string
 * Return: number
 */
int _atoi(const char *str)
{
	int i;
	unsigned int nb;
	int neg;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] && (str[i] == '0' || str[i] == ' '))
		i++;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		neg = str[i++] == '-' ? -neg : neg;
	while (str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + ((int)str[i] - '0');
		i++;
	}
	return (nb * neg);
}
