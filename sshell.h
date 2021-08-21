#ifndef SSHELL_H
#define SSHELL_H

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef struct variables
{
	char *buffer;
	char **array_tokens;
} vars_t;

typedef struct builtins
{
  char *n; 
	void (*f)(vars_t *r);
} builtins_t;

char **_str_tokens(char *buffer, char *delimiter);
char *_realloc(char *ptr, unsigned int size_ini, unsigned int size_fin);
int _execve(vars_t *vars, int num, char **env);
char *get_path(char *cmd, char **env);
char *val_path(char **tokens, char *cmd);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char (*match (vars_t *m))(vars_t *n);
char file_exit(vars_t *vars);
char file_number(vars_t  *vars);
#endif
