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
	FullPath = malloc(lenPath + lenFileName + 1);
	if (!FullPath)
		return (NULL);
	for (i = 0 ; i < lenPath + lenFileName + 1; i++)
		FullPath[i] = '\0';
	_strcpy(FullPath, path);
	FullPath[lenPath] = '/';
	return (_strcat(FullPath, fileName));
}

/**
 * get_path_cmd - get_path_cmd
 * @line : line
 * Return: path command.
 */
char *get_path_cmd(char *line)
{
	char *path;
	char *path_copy;
	char *token;
	char *fullPath = NULL;
	char *cmd;
	struct stat file_stat;

	path = getenv("PATH");
	path_copy = _strdup(path);
	cmd = strtok(line, "\n");
	if (_isinstr(line, ' '))
		cmd = strtok(line, " ");
	if (!stat(cmd, &file_stat))
		return (_strdup(cmd));
	token = strtok(path_copy, ":");
	while (token)
	{
		fullPath = concatPath(token, cmd);
		if (!stat(fullPath, &file_stat))
		{
			free(path_copy);
			return (fullPath);
		}
		free(fullPath);
		fullPath = NULL;
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
