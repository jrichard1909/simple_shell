#include "sshell.h"

/**
 * _realloc: return tokens
 * @ptr: string
 * @size_ini: initial size ptr
 * @size_fin: final size ptr
 * return: new_ptr
 */

char **_realloc(char **ptr, unsigned int size_ini, unsigned int size_fin)
{
	char **new_ptr;
	int i;

	if (size_fin == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}

	if (size_ini == size_fin)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(size_fin);
		if (new_ptr == NULL)
			return (0);
		else
			return (new_ptr);
	}

	new_ptr = malloc(size_fin);
	if (new_ptr == NULL)
		return (0);

	for (i = 0; i < size_ini && i < size_fin; i++)
		new_ptr[i] = ptr[i];
	free(ptr);

	return (new_ptr);
}
