#include "ssh.h"

void run_cmd(char *cmd)
{
	char *env[] = {NULL};

	execve(cmd, &cmd, env);
}