/**
 * _strcpy- copy str
 * @dest: destination
 * @src: src
 * Return: destination
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src && (*(src + i) != '\0'))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
