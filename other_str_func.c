#include "sshell.h"

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

int _strlen(char *s)
{
	int len = 0;
	char *a;

	for (a = s; *a != '\0'; a++)
	{
		len += 1;
	}
	return (len);
}

/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

int numlen(int n)
{
	int len;

	for (len = 0; n > 9 || n < -9; len++)
		n /= 10;

	return (len);
}


/**
 * _str_tokens: return tokens
 * @buffer: string
 * @delimiter: char for delimit
 * @Return: token value
 */

char *num_to_str(int num)
{
	int tens, i = 0, ind_neg = 0, num_len, j;
	char *num_str;

	tens = 1;
	num_len = numlen(num);

	if (num < 0)
		ind_neg = 1;

	num_str = malloc(num_len + 2 + ind_neg);
	if (num_str == NULL)
		return (0);

	if (num < 0)
		num_str[i++] = '-';

	for (j = 0; j < num_len; j++)
		tens *= 10;

	for (; j >= 0; j--)
	{
		if (num < 0)
			num_str[i++] = (num / tens) * -1 + '0';
		else
			num_str[i++] = (num / tens) + '0';
		num %= tens;
		tens /= 10;
	}
	num_str[i] = '\0';
	return (num_str);
}
