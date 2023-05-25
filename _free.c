#include "ssh.h"

/**
 * free_all - free
 * @data :data
 */

void free_all(t_data *data)
{
	free(data->line);
	data->line = NULL;
}
