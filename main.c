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
		return (NULL);
	arr = malloc(count + 1);
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	linecpy = _strdup(line);
	if (linecpy)
	token = strtok(linecpy, " ");
	while (token)
	{
		if (token && *token != ' ')
			arr[i++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	free(linecpy);
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
	t_data data;
	size_t len = 0;
	int nbChar = 0;
	(void)ac;

	data.count_exec = 1;
	while (data.count_exec++)
	{
		if (isatty(0))
			_puts("$ ", STDOUT_FILENO);
		nbChar = getline(&(data.line), &len, stdin);
		if (nbChar == -1)
			free_all(&data, true, EXIT_SUCCESS);
		data.arg = get_arg(data.line);
		data.path_cmd = get_path_cmd(data.line);
		if (data.path_cmd)
			run_cmd(data.path_cmd, data.arg);
		else if (isWhiteSpace(data.line))
		{
			putsError(argv[0], data.count_exec, data.line);
			if (!isatty(0))
				free_all(&data, true, 127);
		}
		free_all(&data, false, false);
		if (!nbChar && !isatty(0))
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
