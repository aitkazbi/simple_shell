#include "ssh.h"

/**
 * _countSep- _countSep
 * @str : data
 * @sep : sep
 * Return: arr.
 */

int _countSep(char *str, char sep)
{
	int count = 0;
	bool isSep = false;
	int i = 0;

	if (*str && *str != sep)
		count++;
	while (str[i])
	{
		if (str[i] == sep)
			isSep = true;
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && isSep)
			count++;
		while (str[i] && str[i] != sep)
			i++;
		isSep = false;
	}
	return (count);
}
/*
 * _strtok - _strtok
 * @str : data
 * @sep : sep
 * Return: arr.
 */
char **_strtok(char *str, char sep)
{
	int count = 0;
	char **arr;
	int i = 0;
	int j = 0;
	int k = 0;

	if (!str || !*str)
		return (NULL);
	count = _countSep(str, sep);

	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;

	i = 0;
	while (str[i] && k < count)
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		arr[k] = malloc(sizeof(char) * (i - j + 1));
		if (!arr[k])
			return (NULL);
		arr[k][i - j] = '\0';
		_strncpy(arr[k], str + j, i - j);
		k++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (arr);
}
