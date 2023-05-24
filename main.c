#include "ssh.h"

/**
 * isWhiteSpace - isWhiteSpaces
 * @str :str to check
 * Return: true or false
 */

bool isWhiteSpace(char *str)
{
	while (*str == ' ')
		str++;
	return (*str ? true : false);
}

/**
 * putsError - puts error
 * @ProgName :ProgName
 * @count : count
 * @cmd : cmd
 */
void putsError(char *ProgName, int count, char *cmd)
{
		_puts(ProgName, STDERR_FILENO);
		_puts(": ", STDERR_FILENO);
		_putnbr(count, true, STDERR_FILENO);
		_puts(": ", STDERR_FILENO);
		_puts(cmd, STDERR_FILENO);
		_puts(": not found\n", STDERR_FILENO);
}
/**
 * main - check the code
 * @ac :argc
 * @argv : argv
 * Return: Always 0.
 */
int main(int ac, char *argv[])
{
	char *lineptr = NULL;
	char *path_cmd;
	size_t len = 0;
	int nbChar = 0;
	char *arr[] = {"", NULL};
	int count = 1;
	(void)ac;

	while (1)
	{
		if (isatty(0))
			_puts("$ ", STDOUT_FILENO);
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			_puts("Error\n", STDERR_FILENO);
			free(lineptr);
			return (EXIT_FAILURE);
		}
		lineptr[_strlen(lineptr)] = '\0';
		path_cmd = get_path_cmd(lineptr);
		if (path_cmd)
			run_cmd(path_cmd, arr);
		if (path_cmd)
			free(path_cmd);
		else if (isWhiteSpace(lineptr))
		{
			putsError(argv[0], count, lineptr);
			if (!isatty(0))
				exit(127);
		}
		if (lineptr)
			free(lineptr);
		lineptr = NULL;

		if (!isatty(0))
			return (EXIT_SUCCESS);
		count++;
	}
	return (EXIT_SUCCESS);
}
