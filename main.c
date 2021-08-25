#include "sshell.h"

/**
 * handle_ctrlc - simple shell
 * @var: void
 */

void handle_ctrlc(int var)
{
	(void)var;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * handle_ctrld - simple shell
 * @vars: argument count
 * @len: argument vectors
 */

void handle_ctrld(vars_t *vars, int len)
{
	if (len == 0)
	{
		free(vars->buffer);
		free(vars->array_tokens);
		exit(0);
	}
}

/**
 * main - simple shell
 * @ac: argument count
 * @av: argument vectors
 * @env: enviroment
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	int len, countline = 0;
	vars_t vars = {NULL, NULL, NULL, 0};
	size_t buff_size = 0;

	(void) ac;

	vars.program = av[0];
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	while ((len = getline(&(vars.buffer), &buff_size, stdin)) != EOF)
	{
		countline++;
		/*signal(SIGINT, handle_ctrlc);*/
		handle_ctrld(&vars, len);
		if (len > 1)
			vars.buffer[len - 1] = '\0';
		vars.array_tokens = _str_tokens(vars.buffer, " ");
		vars.exit_s = check_builtin(&vars, countline, env);
		if (!vars.exit_s)
			vars.exit_s = _execve(&vars, countline, env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(vars.buffer);

	return (0);
}
