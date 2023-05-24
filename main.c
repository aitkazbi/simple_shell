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
	char *arr[] = {NULL};

	while (1)
	{
		_puts("$ ");
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			_puts("Error\n");
			free(lineptr);
			return (1);
		}
		path_cmd = get_path_cmd(lineptr);
		if (path_cmd)
			run_cmd(path_cmd, arr);
		else
			_puts("No such file or directory\n");
		if (path_cmd)
			free(path_cmd);
		if (lineptr)
			free(lineptr);
		lineptr = NULL;
	}
	return (0);
}
