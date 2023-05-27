#include "ssh.h"
/**
 * _puts_env - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */
void _puts_env(t_data *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_puts(data->env[j], STDOUT_FILENO);
		_puts("\n", STDOUT_FILENO);
	}
}

/**
 * setKeyEnv - setKeyEnv
 * @key: name of the variable to set
 * @value: new value
 * @data: data
 * Return: 1.
 */

int setKeyEnv(char *key, char *value, t_data *data)
{
	int i, lenghtKey = 0;
	int isNewKey = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	lenghtKey = _strlen(key);

	for (i = 0; data->env[i]; i++)
	{
		if (_strncmp(key, data->env[i], lenghtKey) &&
		 data->env[i][lenghtKey] == '=')
		{
			isNewKey = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = _strconcat(_strdup(key), "=");
	data->env[i] = _strconcat(data->env[i], value);

	if (isNewKey)
		data->env[i + 1] = NULL;
	return (0);
}

/**
 * getKeyEnv - getKeyEnv
 * @key: key
 * @data: data
 * Return: Return
 */
char *getKeyEnv(char *key, t_data *data)
{
	int i, lenKey = 0;

	if (!key || !data->env)
		return (NULL);
	lenKey = _strlen(key);
	for (i = 0; data->env[i]; i++)
	{
		if (_strncmp(key, data->env[i], lenKey) &&
		 data->env[i][lenKey] == '=')
			return (data->env[i] + lenKey + 1);
	}
	return (NULL);
}

/**
 * ft_env - ft_env
 * @data: data
 * Return: zero or nb
 */
int ft_env(t_data *data)
{
	int i;
	char name[50] = {'\0'};
	char *cp = NULL;

	if (!data->arg[1])
		_puts_env(data);
	else
	{
		for (i = 0; data->arg[1][i]; i++)
		{
			if (data->arg[1][i] == '=')
			{
				cp = _strdup(getKeyEnv(name, data));
				if (cp != NULL)
					setKeyEnv(name, data->arg[1] + i + 1, data);
				_puts_env(data);
				if (getKeyEnv(name, data) == NULL)
				{
					_puts(data->arg[1], STDOUT_FILENO);
					_puts("\n", STDOUT_FILENO);
				}
				else
				{
					setKeyEnv(name, cp, data);
					free(cp);
				}
				return (0);
			}
			name[i] = data->arg[1][i];
		}
		errno = 2;
		perror(data->cmd);
		errno = 127;
	}
	return (0);
}
