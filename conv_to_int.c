#include "monty.h"

/**
 * conv_to_int - converts push arguments to integer
 * @n: argument to be checked and converted
 *
 * Return: converted integer or -1 on failure
 */
int conv_to_int(char *n)
{
	int num, i;

	if (n == NULL)
		return ('a');

	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[i] == '-')
			continue;

		if (isdigit(n[i]) == 0)
			return ('a');
	}
	num = atoi(n);

	return (num);
}
