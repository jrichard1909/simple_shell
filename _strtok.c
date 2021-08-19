#include "sshell.h"

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

char **_str_tokens(char *buffer, char *delimiter)
{
	char **token = NULL;
	size_t i = 0;
	unsigned int max_count = 10;

	if (buffer == NULL)
		return (NULL);
	token = malloc(sizeof(char*)*max_count);

	if (token == NULL)
		return (NULL);

	while ((token[i] = strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == max_count)
		{
			token = _realloc(token, max_count, 2 * max_count);
			if (token == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (token);
}
