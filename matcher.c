#include "sshell.h"

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

int check_builtin(vars_t vars, int num, char **env)
{
	int i;
	builtins_t check[] = {
		{"env", builtin_env},
		{"exit", builtin_exit},
		{NULL, NULL}};
	
	for (i = 0; check[i].name; i++)
	{
		if (_strcmp(check[i].name,vars.array_tokens[0]) == 0)
		{
			return (check[i].f(&vars, num, env));
		}
	}

	return (0);
}

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

int builtin_env(vars_t *vars, int num, char **env)
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (1);
}

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

int builtin_exit(vars_t *vars, int num, char **env)
{
	int exit_status = 0;
	char* num_str;

	if (vars->array_tokens[1] != NULL)
		exit_status = _atoi(vars->array_tokens[1]);
	else if (vars->exit_s != 0)
		exit_status = vars->exit_s;

	if (exit_status == -1)
	{
		write(STDIN_FILENO, vars->program, _strlen(vars->program));
		write(STDIN_FILENO, ": ", 2);
		num_str = num_to_str(num);
		write(STDIN_FILENO, num_str, _strlen(num_str));
		write(STDIN_FILENO, ": exit: Ilegal number: ", 23);
		write(STDIN_FILENO, vars->array_tokens[1], _strlen(vars->array_tokens[1]));
		write(STDIN_FILENO, "\n", 1);
		return (2);	
	}

	
	
	exit(exit_status);
}
