#include "sshell.h"

/**
 * val_path - validate path for command
 * @tokens: strings token
 * @cmd: command call
 * Return: pointer char path
 */

char *val_path(char **tokens, char *cmd)
{
	char *path;
	int i = 0;

	while (tokens[i] != NULL)
	{
		path = _strdup(tokens[i]);
		path = _strcat(path, "/");
		path = _strcat(path, cmd);
		if (access(path, X_OK) == 0)
		{
			free(tokens);
			return (path);
		}
		i++;
		free(path);
	}
	free(tokens);
	return (0);
}

/**
 * get_path - get path for command
 * @cmd: command call
 * @env: environment
 * Return: token value
 */

char *get_path(char *cmd, char **env)
{
	char *path, str[6], **tokens, *path_ok;
	int i = 0, j, c;

	(void) env;
	while (environ[i] != NULL)
	{
		for (j = 0; j < 5; j++)
			str[j] = environ[i][j];
		str[j] = '\0';

		if (_strcmp(str, "PATH=") == 0)
			break;
		i++;
	}

	if (environ[i] != NULL)
	{
		c = j;
		while (environ[i][j])
			j++;

		path = malloc(j - c + 1);
		if (path == NULL)
			return (0);
		while (environ[i][c])
		{
			path[c - 5] = environ[i][c];
			c++;
		}
		path[c - 5] = '\0';
		tokens = _str_tokens(path, ":");
		path_ok = val_path(tokens, cmd);
		free(path);
		return (path_ok);
	}

	return (0);
}
