#include "ssh.h"

char *concatPath(char *path, char *fileName)
{
	char *FullPath = NULL;
	int lenPath = 0;
	int lenFileName = 0;

	if (!path || !fileName)
		return(NULL);
	lenPath = strlen(path);
	lenFileName = strlen(fileName);
	FullPath = malloc( lenPath + lenFileName + 1);
	if (!FullPath)
		return NULL;
	FullPath = strcpy(FullPath, path);
	FullPath[lenPath] = '/';
	return(strcat(FullPath, fileName));
}

char *get_path_cmd(char *line)
{
	char *path;
	char *token;
	char *fullPath;
	char *cmd;
    struct stat file_stat;

	path = getenv("PATH");
	cmd = strtok(line, "\n");
	token = strtok(path, ":");

	while (token)
	{
		fullPath = concatPath(token, cmd);
		if (!stat(fullPath, &file_stat))
			return (fullPath);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
