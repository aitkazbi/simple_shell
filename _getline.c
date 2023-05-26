#include "ssh.h"
# define L 5000
# define TMP 5001

/**
 * _getline- _getline
 * @fd: fd
 * @line : line
 * Return: 1 or 0 or -1
 */

int _getline(int fd, char **line)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;
	static int buffer_size;
	int line_size = 0;
	int i;

	if (buffer_index >= buffer_size)
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		buffer_index = 0;
	}

	if (buffer_size == -1)
		return (-1);
	else if (buffer_size == 0 && line_size == 0)
		return (0);

	while (buffer_index < buffer_size)
	{
		if (buffer[buffer_index] == '\n')
		{
			(*line) = (char *)malloc((line_size + 1) * sizeof(char));
			for (i = 0; i < line_size; i++)
				(*line)[i] = buffer[i];
			(*line)[line_size] = '\0';
			buffer_index++;
			return (1);
		}

		line_size++;
		buffer_index++;
	}

	(*line) = (char *)malloc((line_size + 1) * sizeof(char));
	for (i = 0; i < line_size; i++)
		(*line)[i] = buffer[i];
	(*line)[line_size] = '\0';

	return (1);
}

