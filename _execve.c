#include "sshell.h"

/**
 * print_err_com - print error execve
 * @vars: structure vars
 * @num: num of line
 */

void print_err_com(vars_t *vars, int num)
{
	char *num_str;

	num_str = num_to_str(num);
	write(STDERR_FILENO, vars->program, _strlen(vars->program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num_str, _strlen(num_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, vars->array_tokens[0], _strlen(vars->array_tokens[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	free(num_str);
}



/**
 * _execve - system call
 * @vars: string
 * @num: char for delimit
 * @env: enviroment
 * Return: 0
 */

int _execve(vars_t *vars, int num, char **env)
{
	char *cmd;
	int status = 0;
	pid_t pid;
	
	pid = fork();
	if (pid == 0)
	{
		if (access(vars->array_tokens[0], X_OK) == 0)
		{
			cmd = vars->array_tokens[0];
			if (execve(cmd, vars->array_tokens, env) == -1)
				perror(vars->program);
		}
		else
		{
			cmd = get_path(vars->array_tokens[0], env);
			if (cmd != NULL)
			{
				if (execve(cmd, vars->array_tokens, env) == -1)
					perror(vars->program);
				free(cmd);
			}
			else
			{
				errno = 127;
				print_err_com(vars, num);
			}
			free(vars->buffer);
		}
		free(vars->array_tokens);
		_exit(errno);
	}
	wait(&status);
	free(vars->array_tokens);
	errno = status % 255;
	return (errno);
}
