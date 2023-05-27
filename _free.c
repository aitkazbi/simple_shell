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
	data->line = NULL;
	if (data->cmd)
		free(data->cmd);
	data->cmd = NULL;
	if (data->path_cmd)
		free(data->path_cmd);
	data->path_cmd = NULL;
	while (data->arg && data->arg[i])
	{
		free(data->arg[i]);
		data->arg[i++] = NULL;
	}
	if (data->arg)
		free(data->arg);
	data->arg = NULL;
	if (isExit)
		exit(status);
	data->isEcho = false;
	data->isExit = false;
	data->issetenv = false;
	data->isunsetenv = false;
	data->isenv = false;
}
