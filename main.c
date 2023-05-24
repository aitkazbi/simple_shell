#include "ssh.h"

/**
 * main - check the code
 * @ac :argc
 * @argv : argv
 * Return: Always 0.
 */
int main(int __attribute__((unused)) ac, char *__attribute__((unused)) argv[])
{
	char *lineptr = NULL;
	char *path_cmd;
	size_t len = 0;
	int nbChar = 0;
	char *arr[] = {NULL};

	while (1)
	{
		if (isatty(0))
			_puts("$ ");
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			_puts("Error\n");
			free(lineptr);
			return (EXIT_FAILURE);
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
		if (!isatty(0))
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
