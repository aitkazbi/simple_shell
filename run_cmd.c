#include "ssh.h"

/**
 * run_cmd - execute command
 * @cmd : command
 * @argv : argv
 * Return: None.
 */
void run_cmd(char *cmd, char **argv)
{
	pid_t pid;
	int status;
	/*char *arg[] = {"ls", "-la", NULL};*/

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
