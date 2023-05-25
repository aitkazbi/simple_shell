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
 * removeWhiteSpace - removeWhiteSpace
 * @line :line
 */
void removeWhiteSpace(char **line)
{
	while (!*line && **line == ' ')
		(*line)++;
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
 * get_arg - get_arg
 * @line :line
 * Return: arr
 */

char **get_arg(char *line)
{
	char *token;
	char *linecpy;
	char **arr;
	int count = 0;
	int i = 0;

	line[_strlen(line) - 1] = '\0';
	removeWhiteSpace(&line);
	linecpy = _strdup(line);
	token = strtok(linecpy, " ");
	while (token)
	{
		if (token && *token != ' ')
			count++;
		token = strtok(NULL, " ");
	}
	free(linecpy);
	if (count == 0)
		NULL;
	arr = malloc(count + 1);
	arr[count] = NULL;
	linecpy = _strdup(line);
	token = strtok(linecpy, " ");
	while (token)
	{
		if (token && *token != ' ')
			arr[i++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	free(linecpy);
	printf("here\n");
	return (arr);
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
	char **arr = NULL;
	int count = 1;
	(void)ac;

	while (count++)
	{
		if (isatty(0))
			_puts("$ ", STDOUT_FILENO);
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			free(lineptr);
			return (EXIT_SUCCESS);
		}
		arr = get_arg(lineptr);
		path_cmd = get_path_cmd(lineptr);
		if (path_cmd)
		{
			run_cmd(path_cmd, arr);
			free(path_cmd);
		}
		else if (*lineptr)
		{
			putsError(argv[0], count, lineptr);
			if (!isatty(0))
				exit(127);
		}
		if (lineptr)
			free(lineptr);
		lineptr = NULL;

		if (!nbChar && !isatty(0))
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
