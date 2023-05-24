#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ssh.h"

/*void run_cmd(char *cmd)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Error");
        exit(-1);
    }
    else if (pid == 0)
    {
        if (system(cmd) == -1)
        {
            printf("Failed command\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        wait(NULL);
    }
}
*/
void run_cmd(char *cmd)
{
    pid_t pid = fork();
 char *envp[] = {NULL};
    if (pid < 0)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *args[4];
        args[0] = "/bin/sh";
        args[1] = "-c";
        args[2] = cmd;
        args[3] = NULL;
        
        if (execve("/bin/sh", args, envp) == -1)
        {
            printf("Failed command\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        wait(NULL);
    }
}