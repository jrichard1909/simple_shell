#include "sshell.h"

/**
 * _strdup - return tokens
 * @str: string
 * Return: token value
 */

char *_strdup(char *str)
{
	int n, i = 0;
	char *s;

	while (str[i])
		i++;

	n = i;

	s = malloc(n);
	for (i = 0; i < n; i++)
		s[i] = str[i];

	return (s);
}
