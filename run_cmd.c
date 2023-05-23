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


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ssh.h"

void run_cmd(char *cmd)
{ 
	char *args[2];

    pid_t pid = fork();
    
    if (pid < 0)
    {
        printf("Error: Failed to fork\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Processus enfant*/

        args[0] = cmd;
        args[1] = NULL;
        
        if (execvp(cmd, args) == -1)
        {
            printf("Error: Failed to execute command\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Processus parent*/
        wait(NULL);
    }
}
