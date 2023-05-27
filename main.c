#include "ssh.h"

/**
 * isWhiteSpace - isWhiteSpaces
 * @str :str to check
 * Return: true or false
 */

bool isWhiteSpace(char *str)
{
	while (*str == ' ')
		str++;
	return (*str ? true : false);
}

/**
 * putsError - puts error
 * @ProgName :ProgName
 * @count : count
 * @cmd : cmd
 */
void putsError(char *ProgName, int count, char *cmd)
{
	_puts(ProgName, STDERR_FILENO);
	_puts(": ", STDERR_FILENO);
	_putnbr(count, true, STDERR_FILENO);
	_puts(": ", STDERR_FILENO);
	_puts(cmd, STDERR_FILENO);
	_puts(": not found\n", STDERR_FILENO);
}

/**
 * init_all - init_all
 * @data: data
 * @argv: argv
 * @env: env
 */

void init_all(t_data *data, char **argv, char **env)
{
	int i = 0;

	data->progName = argv[0];
	data->count_exec = 0;
	data->line = NULL;
	data->arg = NULL;
	data->cmd = NULL;
	data->path_cmd = NULL;
	data->isEcho = false;
	data->isExit = false;
	data->issetenv = false;
	data->isunsetenv = false;
	data->isenv = false;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_dup(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;
}

/**
 * main - check the code
 * @ac :argc
 * @argv : argv
 * @env : env
 * Return: Always 0.
 */
int main(int ac, char *argv[], char *env[])
{
	t_data data;
	int retGetLine = 0;
	size_t len;

	(void)ac;
	init_all(&data, argv, env);
	while (++data.count_exec)
	{
		if (isatty(0))
			_puts("$ ", STDOUT_FILENO);
		retGetLine = getline(&(data.line), &len, stdin);
		if (retGetLine == -1)
			free_all(&data, true, EXIT_SUCCESS);
		get_arg(&data);
		if (data.cmd)
			get_path_cmd(&data);
		if (data.path_cmd || data.isEcho || data.isExit || data.isenv)
			run_cmd(&data, data.path_cmd, data.arg);
		else if (isWhiteSpace(data.line))
		{
			putsError(argv[0], data.count_exec, data.line);
			if (!isatty(0))
				free_all(&data, true, EXIT_SUCCESS); /*127*/
		}
		free_all(&data, false, false);
		if (retGetLine <= 0 && !isatty(0))
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
