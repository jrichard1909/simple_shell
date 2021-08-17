#ifndef SSHELL_H
#define SSHELL.H

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/types.h>


typedef struct variables
{
	char *buffer;
	char **array_tokens;
} vars_t;

typedef struct builtins
{
	void (*f)(vars_t *)
} builtins_t


#endif
