/**
 * _strcat- concat src & dest
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcat(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (dest && *dest)
		dest++;
	while (src && *src)
		*dest++ = *src++;
	return (ptr);
}
