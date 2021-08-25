#include "sshell.h"

/**
 * _execve - system call
 * @vars: string
 * @num: char for delimit
 * @env: enviroment
 * Return: 0
 */

int _execve(vars_t *vars, int num, char **env)
{
	char *cmd, *num_str;
	int status = 0, ind_path = 0;
	pid_t pid;

	if (access(vars->array_tokens[0], X_OK) == 0)
		cmd = vars->array_tokens[0];
	else
	{
		cmd = get_path(vars->array_tokens[0], env);
		ind_path = 1;
		if (cmd == NULL)
		{
			num_str = num_to_str(num);
			write(STDOUT_FILENO, vars->program, _strlen(vars->program));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, num_str, _strlen(num_str));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, vars->array_tokens[0], _strlen(vars->array_tokens[0]));
			write(STDOUT_FILENO, ": not found\n", 12);
			/*free(vars->buffer);*/
			free(vars->array_tokens);
			free(cmd);
			free(num_str);
			return (127);
		}
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, vars->array_tokens, env);
	}

	wait(&status);
	/*free(vars->buffer);*/
	free(vars->array_tokens);
	if (ind_path == 1)
		free(cmd);

	return (0);
}
