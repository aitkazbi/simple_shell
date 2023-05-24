#include "ssh.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *lineptr = NULL;
	char *path_cmd;
	size_t len = 0;
	int nbChar = 0;
	char *argv[] = {NULL};

	while (1)
	{
		printf("SH-> ");
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			printf("Error\n");
			free(lineptr);
			return (1);
		}
		path_cmd = get_path_cmd(lineptr);
		run_cmd(path_cmd, argv);
		if (path_cmd)
			free(path_cmd);
		if (lineptr)
			free(lineptr);
		lineptr = NULL;
	}
	return (0);
}
