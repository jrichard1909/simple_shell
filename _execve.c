#include "sshell.h"

/**
 * :_execve return tokens
 * @vars: string
 * @num: char for delimit
 * @Return: 0
 */

int _execve(vars_t *vars, int num, char **env)
{
	char *cmd;
	int status = 0;
	pid_t pid;

	if (access(vars->array_tokens[0], X_OK) == 0)
		cmd = vars->array_tokens[0];
	else
	{
		cmd = get_path(vars->array_tokens[0], env);
		if (cmd == NULL)
		{
			write(STDOUT_FILENO, "not found command\n", 18);
			return (127);
		}
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, vars->array_tokens, env);
	}

	wait(&status);

	return (0);
}
