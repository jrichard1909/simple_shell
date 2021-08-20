#include "sshell.h"

/**
 * main - simple shell
 * @ac: argument count
 * @av: argument vectors
 * @env: enviroment
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	int len, countline = 0, exit_s;
	vars_t vars ={NULL, NULL};
	size_t buff_size = 0;
	
	write(STDOUT_FILENO, "$ ", 2);
	while((len = getline(&(vars.buffer), &buff_size, stdin)) != EOF)
	{
		countline++;
		if(len > 1)
			vars.buffer[len - 1] = '\0';
		vars.array_tokens = _str_tokens(vars.buffer, " ");
		exit_s = _execve(&vars, countline, env);
		write(STDOUT_FILENO, "$ ", 2);

	}
	write(STDOUT_FILENO, "\n", 1);

	return (0);
}
