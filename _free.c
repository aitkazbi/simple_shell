#include "ssh.h"

/**
 * free_all - free
 * @data :data
 * @isExit : isExist
 * @status : status
 */

void free_all(t_data *data, bool isExit, int status)
{
	int i = 0;

	if (data->line)
		free(data->line);
	if (data->cmd)
		free(data->cmd);
	if (data->path_cmd)
		free(data->path_cmd);
	data->line = NULL;
	data->cmd = NULL;
	data->path_cmd = NULL;
	while (data->arg && data->arg[i])
	{
		free(data->arg[i]);
		data->arg[i] = NULL;
		i++;
	}
	if (data->arg)
		free(data->arg);
	data->arg = NULL;
	if (isExit)
		exit(status);
}
