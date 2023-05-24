#ifndef SSH_H
#define SSH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>

extern char **environ;
void run_cmd(char *cmd, char **argv);
char *get_path_cmd(char *line);

int _isinstr(char *str, char toFind);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _putnbr(unsigned long int a, bool isToPut, int fd);
void _puts(char *str, int fd);
int _putchar(char c, int fd);

#endif
