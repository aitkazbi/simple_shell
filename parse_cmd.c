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
	FullPath = malloc(lenPath + lenFileName + 2);
	if (!FullPath)
		return (NULL);
	for (i = 0; i < (lenPath + lenFileName + 2); i++)
		FullPath[i] = '\0';
	_strcpy(FullPath, path);
	FullPath[lenPath] = '/';
	_strcat(FullPath, fileName);
	return (FullPath);
}

/**
 * get_path_cmd - get_path_cmd
 * @data : data
 * Return: path command.
 */
void get_path_cmd(t_data *data)
{
	int i = 0;
	char **tokens;
	char *fullPath;
	struct stat file_stat;

	if (!access(data->cmd, X_OK) && stat(data->cmd, &file_stat) != -1)
	{
		data->path_cmd = _strdup(data->cmd);
		return;
	}

	tokens = _strtok(getenv("PATH"), ':');
	while (tokens[i])
	{
		fullPath = NULL;
		fullPath = concatPath(tokens[i], data->cmd);

		if (!access(fullPath, X_OK) && stat(fullPath, &file_stat) != -1)
		{
			i = 0;
			while (tokens && tokens[i])
				free(tokens[i++]);
			free(tokens);
			data->path_cmd = fullPath;
			return;
		}
		if (fullPath)
			free(fullPath);
		i++;
	}
	i = 0;
	while (tokens && tokens[i])
		free(tokens[i++]);
	free(tokens);
	data->path_cmd = NULL;
}
