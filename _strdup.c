#include "sshell.h"

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
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
