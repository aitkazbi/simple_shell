#include "ssh.h"


int main()
{
	char *lineptr = NULL;
	char *path_cmd;
	size_t len = 0;
	size_t nbChar = 0;

	while(1)
	{
		printf("SH-> ");
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			printf("Error\n");
			return (1);
		}
		path_cmd = get_path_cmd(lineptr);
		run_cmd(path_cmd);
	}
	return (0);
}
