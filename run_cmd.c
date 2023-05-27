#include "ssh.h"

/**
 * run_built - run built
 * @data :data
 * Return: arr
 */

bool run_built(t_data *data)
{
	if (data->isEcho)
	{
		_echo(data->arg);
		return (true);
	}
	if (data->isExit)
	{
		ft_exit(data);
		putsExitError(data);
		return (true);
	}
	if (data->isenv)
	{
		ft_env(data);
		return (true);
	}
	if (data->issetenv)
	{
		ft_env(data);
		return (true);
	}
	if (data->isunsetenv)
	{
		ft_exit(data);
		return (true);
	}
	return (false);
}
/**
 * run_cmd - execute command
 * @cmd : command
 * @argv : argv
 * @data : data
 * Return: None.
 */
void run_cmd(t_data *data, char *cmd, char **argv)
{
	pid_t pid;
	int status;

	if (run_built(data))
		return;

	pid = fork();

	if (pid < 0)
		exit(127);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		if (execve(cmd, argv, __environ) == -1)
		{
			exit(127);
		}
		exit(0);
	}
}
