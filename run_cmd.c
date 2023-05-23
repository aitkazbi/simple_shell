#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ssh.h"
/*#include "ssh.h"

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
}*/

void run_cmd(char *cmd)
{ 
	char *args[2];

    pid_t pid = fork();
    
    if (pid < 0)
    {
        printf("Error");
        exit(-1);
    }
    else if (pid == 0)
    {
        /* enfant */

        args[0] = cmd;
        args[1] = NULL;
        
        if (execvp(cmd, args) == -1)
        {
            printf("Error: Failed command\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* parent*/
        wait(NULL);
    }
}
