#include "ssh.h"


int main()
{
	/*char *lineptr = NULL;
	char *path_cmd;
	size_t len = 0;
	int nbChar = 0;

	while(1)
	{
		printf("SH->");
		lineptr = NULL;
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			printf("Error\n");
			continue;
		}
		
		path_cmd = get_path_cmd(lineptr);
		printf("test:%s pid:%d\n",path_cmd ,getpid());
		run_cmd(path_cmd);
		run_cmd(lineptr);
	}
		free(lineptr);
	
	return (0);*/

 char *command = NULL;
    size_t command_len = 0;
    ssize_t line_len;

    while (1)
    {
        printf("SH->");

        line_len = getline(&command, &command_len, stdin);
        if (line_len == -1)
        {
            printf("Error reading command\n");
            continue;
        }

        /* Supprimer le caractère de nouvelle ligne*/
        command[strcspn(command, "\n")] = '\0';

        run_cmd(command);
    }

    free(command);

    return 0;
}
