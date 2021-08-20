#include "sshell.h"

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

char *val_path(char **tokens, char *cmd)
{
	char *path;
	int i = 0;

	while(tokens[i] != NULL)
	{
		path = _strdup(tokens[i]);
		path = _strcat(path, "/");
		path = _strcat(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}

	return (0);
}

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

char *get_path(char *cmd, char **env)
{
	char *path, str[5], **tokens;
	int i = 0, j, c;
	
	while (env[i] != NULL)
	{
		for (j = 0; j < 4; j++)
			str[j] = env[i][j];
		str[j] = '\0';

		if (_strcmp(str, "PATH") == 0)
			break;
		i++;
	}

	if (env[i] != NULL)
	{
		c = j;
		while (env[i][j])
			j++;
		
		path = malloc(j - c + 1);
		if (path == NULL)
			return (0);
		while (env[i][c])
		{
			path[c - 5] = env[i][c];
			c++;
		}
		tokens = _str_tokens(path, ":");

		return (val_path(tokens, cmd));
	}

	return (0);
}
