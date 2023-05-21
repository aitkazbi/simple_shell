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

void run_cmd(char *cmd)
{
	char *env[] = {NULL};

	execve(cmd, &cmd, env);
}

int main()
{
	char *lineptr = NULL;
	char *path_cmd;
	size_t len = 0;
	size_t nbChar = 0;

	while(1)
	{
		printf("SH-> ");
		nbChar = getline(&lineptr, &len, stdin);
		if (nbChar == -1)
		{
			printf("Error\n");
			return (1);
		}
		path_cmd = get_path_cmd(lineptr);
		run_cmd(path_cmd);
		/*printf("len = %ld, %s", nbChar, lineptr);*/
	}
	return (0);
}
