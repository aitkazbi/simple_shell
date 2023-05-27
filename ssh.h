#ifndef SSH_H
#define SSH_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
/**
 * struct s_data- struct data
 * @arg: arg
 * @line: line
 * @cmd: cmd
 * @isEcho: isEcho
 * @path_cmd: path_cmd
 * @count_arg: count_arg
 * @count_exec : count_exec
 */
typedef struct s_data
{
	char *line;
	char *path_cmd;
	char *cmd;
	bool isEcho;
	char **arg;
	int count_exec;
	int count_arg;
} t_data;

void get_arg(t_data *data);
void run_cmd(t_data *data, char *cmd, char **argv);
void get_path_cmd(t_data *data);
void free_all(t_data *data, bool isExit, int codeExit);
int _getline(int fd, char **line);

int _isinstr(char *str, char toFind);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _putnbr(unsigned long int a, bool isToPut, int fd);
void _puts(char *str, int fd);
int _putchar(char c, int fd);
char **_strtok(char *str, char sep);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _echo(char **arg);
#endif
