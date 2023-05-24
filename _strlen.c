/**
 * _strlen- len(s)
 * @s: string
 * Return: len of s
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
