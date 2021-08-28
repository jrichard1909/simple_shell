#include "sshell.h"

/**
 * builtin_env -  return tokens
 * @vars: string
 * @num: char for delimit
 * @env: environment
 * Return: token value
 */

int builtin_env(vars_t *vars, int num, char **env)
{
	int i = 0;

	(void)vars;
	(void)num;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	free(vars->array_tokens);

	return (1);
}

/**
 * builtin_exit - return tokens
 * @vars: string
 * @num: char for delimit
 * @env: environment
 * Return: token value
 */

int builtin_exit(vars_t *vars, int num, char **env)
{
	char *num_str;
	(void)env;

	if (vars->array_tokens[1] != NULL)
	{
		errno = 0;
		errno = _atoi(vars->array_tokens[1]);
		if (errno == -1)
		{
			write(STDERR_FILENO, vars->program, _strlen(vars->program));
			write(STDERR_FILENO, ": ", 2);
			num_str = num_to_str(num);
			write(STDERR_FILENO, num_str, _strlen(num_str));
			write(STDERR_FILENO, ": exit: Ilegal number: ", 23);
			write(STDERR_FILENO, vars->array_tokens[1], _strlen(vars->array_tokens[1]));
			write(STDERR_FILENO, "\n", 1);
			free(num_str);
			free(vars->array_tokens);
			errno = 2;
			return (errno);
		}
	}
	free(vars->buffer);
	free(vars->array_tokens);
	if (errno > 255)
		errno %= 256;
	exit(errno);
}

/**
 * check_builtin - return tokens
 * @vars: structure vars
 * @num:  string
 * @env: environment
 * Return: token value
 */

int check_builtin(vars_t *vars, int num, char **env)
{
	int i;
	builtins_t check[] = {
		{"env", builtin_env},
		{"exit", builtin_exit},
		{NULL, NULL}};
	for (i = 0; check[i].name; i++)
	{
		if (_strcmp(check[i].name, vars->array_tokens[0]) == 0)
			return (check[i].f(vars, num, env));
	}

	return (0);
}

