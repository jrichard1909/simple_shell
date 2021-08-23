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
	char *program;
} vars_t;

typedef struct builtins
{
	char *name;
	int (*f)(vars_t *, int num_line, char **env);
} builtins_t;

char **_str_tokens(char *buffer, char *delimiter);
char *_realloc(char *ptr, unsigned int size_ini, unsigned int size_fin);
int _execve(vars_t *vars, int num, char **env);
char *get_path(char *cmd, char **env);
char *val_path(char **tokens, char *cmd);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int check_builtin(vars_t vars, int num, char **env);
int builtin_env(vars_t *vars, int num_line, char **env);
int builtin_exit(vars_t *vars, int num_line, char **env);
int _strlen(char *s);
int numlen(int n);
char *num_to_str(int num);

#endif
