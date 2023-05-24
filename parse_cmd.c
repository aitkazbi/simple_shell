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

	if (!path || !fileName)
		return (NULL);
	lenPath = strlen(path);
	lenFileName = strlen(fileName);
	FullPath = malloc(lenPath + lenFileName + 1);
	if (!FullPath)
		return (NULL);
	strcpy(FullPath, path);
	FullPath[lenPath] = '/';
	return (strcat(FullPath, fileName));
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
	char *fullPath;
	char *cmd;
	struct stat file_stat;

	path = getenv("PATH");
	path_copy = strdup(path);
	cmd = strtok(line, "\n");
	if (_isinstr(line, ' '))
		cmd = strtok(line, " ");
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
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
