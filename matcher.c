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
		if (check[i].name == vars.array_tokens[0])
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
	return (0);
}

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

int builtin_exit(vars_t *vars, int num, char **env)
{

	return (0);
}
