#include "sshell.h"

/**
 * _strcat - return tokens
 * @dest: string
 * @src: char for delimit
 * Return: token value
 */

char *_strcat(char *dest, char *src)
{
	int len = 0, len2 = 0, total_len = 0, j = 0;

	while (dest[len])
	{
		len++;
		total_len++;
	}
	while (src[len2])
	{
		len2++;
		total_len++;
	}

	dest = _realloc(dest, len, total_len + 1);

	while (src[j] != '\0')
		dest[len++] = src[j++];

	dest[len] = '\0';

	return (dest);
}
