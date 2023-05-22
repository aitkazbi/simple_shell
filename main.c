#include "ssh.h"


int main()
{
	char *lineptr = NULL;
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
			return (1);
		}
		path_cmd = get_path_cmd(lineptr);
		printf("test:%s pid:%d\n",path_cmd ,getpid());
		run_cmd(path_cmd);
		free(lineptr);
	}
	return (0);
}
