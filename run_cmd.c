#include "ssh.h"

void run_cmd(char *cmd)
{
	char *env[] = {NULL};
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{				
		printf("Error");
		exit(-1);
	}
	else if (pid == 0)
	{
	 execve(cmd, &cmd, env);
	}
	else
	{
		wait (NULL);
	}
}
