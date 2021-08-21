#include "sshell.h"

/**
 * _str_tokens: return tokens
 * @Return: token value
 */
char (*match (vars_t *m))(vars_t *n)
{
	int i;
	builtins_t op[]={
		{"exit", file_exit},
		{"hi", file_number},
		{NULL,NULL}
	};

	for (i = 0 ; op[i].f != NULL ; i++)
	{
		if (strcmp(op[i].n,(char*)m->array_tokens[0]) == 0)
			break;
	}
	return(op[i].f);
}
char file_exit(vars_t *vars)
{
	exit(98);
}
char file_number(vars_t *vars)
{
	printf("Hello world\n");
	return(0);
}

