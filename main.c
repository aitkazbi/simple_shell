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
	char *ptr;

	ptr = *line;
	while (!*line && **line == ' ')
		(*line)++;
	*line = _strdup(*line);
	free(ptr);
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
 * @data :data
 * Return: arr
 */

void get_arg(t_data *data)
{
	char *token;
	char *linecpy;
	int count = 0;

	data->count_arg = 0;
	data->line[_strlen(data->line) - 1] = '\0';
	removeWhiteSpace(&data->line);
	linecpy = _strdup(data->line);
	token = strtok(linecpy, " ");
	data->cmd = _strdup(token);
	while (token)
	{
		if (token && *token != ' ')
			count++;
		token = strtok(NULL, " ");
	}
	free(linecpy);
	if (count == 0)
		data->arg = NULL;
	data->arg = malloc(sizeof(char *) * (count + 1));
	if (!data->arg)
		return;
	data->arg[count] = NULL;

	linecpy = _strdup(data->line);
	if (linecpy)
		token = strtok(linecpy, " ");

	while (token)
	{
		if (token && *token != ' ')
			data->arg[data->count_arg++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	free(linecpy);
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
	int retGetLine = 0;
	size_t len;

	(void)ac;
	data.count_exec = 1;
	data.line = NULL;
	data.arg = NULL;
	data.cmd = NULL;
	data.path_cmd = NULL;
	while (data.count_exec++)
	{
		if (isatty(0))
			_puts("$ ", STDOUT_FILENO);
		retGetLine = getline(&(data.line), &len, stdin);
		/*retGetLine = _getline(STDIN_FILENO, &(data.line));*/
		/*printf("line = %s\n", data.line);*/
		if (retGetLine == -1)
			free_all(&data, true, EXIT_SUCCESS);
		get_arg(&data);
		if (data.cmd)
			get_path_cmd(&data);
		if (data.path_cmd)
			run_cmd(data.path_cmd, data.arg);
		else if (isWhiteSpace(data.line))
		{
			putsError(argv[0], data.count_exec, data.line);
			if (!isatty(0))
				free_all(&data, true, EXIT_SUCCESS); /*127*/
		}
		free_all(&data, false, false);
		if (retGetLine <= 0 && !isatty(0))
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
