#include "sshell.h"

/**
 * _strcmp - return tokens
 * @s1: string
 * @s2: char for delimit
 * Return: token value
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		return (1);
	}

	return (0);
}
