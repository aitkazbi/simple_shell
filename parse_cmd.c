#include "ssh.h"

/**
 * concatPath - concatinate path
 * @path : path
 * @fileName: filename
 * Return: FullPath.
 */
char *concatPath(char *path, char *fileName)
{
	char *FullPath = NULL;
	int lenPath = 0;
	int lenFileName = 0;
	int i = 0;

	if (!path || !fileName)
		return (NULL);
	lenPath = _strlen(path);
	lenFileName = _strlen(fileName);
	FullPath = malloc(sizeof(char *) * (lenPath + lenFileName + 1));
	if (!FullPath)
		return (NULL);
	for (i = 0; i < lenPath + lenFileName + 1; i++)
		FullPath[i] = '\0';
	_strcpy(FullPath, path);
	FullPath[lenPath] = '/';
	return (_strcat(FullPath, fileName));
}

/**
 * get_path_cmd - get_path_cmd
 * @data : data
 * Return: path command.
 */
void get_path_cmd(t_data *data)
{
	char *path;
	char *path_copy;
	char *token;
	char *fullPath = NULL;
	struct stat file_stat;

	path = getenv("PATH");

	if (stat(data->cmd, &file_stat) != -1)
	{
		data->path_cmd = _strdup(data->cmd);
		return;
	}
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		fullPath = concatPath(token, data->cmd);
		if (stat(fullPath, &file_stat) != -1)
		{
			if (path_copy)
				free(path_copy);
			data->path_cmd = fullPath;
			return;
		}
		if (fullPath)
			free(fullPath);
		fullPath = NULL;
		token = strtok(NULL, ":");
	}
	if (path_copy)
		free(path_copy);
	data->path_cmd = NULL;
}

/*free_all(data, true, 1);*/
