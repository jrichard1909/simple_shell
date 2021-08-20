

int _atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num *= 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			return (0);
		i++;
	}
	return (num);
}