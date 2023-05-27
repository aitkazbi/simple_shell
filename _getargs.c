#include "ssh.h"
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
 * get_arg - get_arg
 * @data :data
 * Return: arr
 */

void get_arg(t_data *data)
{
	char **ptr;

	data->count_arg = 0;
	data->line[_strlen(data->line) - 1] = '\0';

	data->arg = _strtok(data->line, ' ');
	ptr = data->arg;
	while (*ptr)
	{
		data->count_arg++;
		ptr++;
	}
	data->cmd = _strdup(data->arg[0]);
}
