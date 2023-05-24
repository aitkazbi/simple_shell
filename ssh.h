#ifndef SSH_H
#define SSH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void run_cmd(char *cmd, char **argv);
char *get_path_cmd(char *line);
int _isinstr(char *str, char toFind);

#endif
