#include "monty.h"
/**
 * check_digits - checks if the whole array contains digits
 * @token: array to check
 * Return: 0 if everything is digit, else 1
 **/
int check_digits(char *token)
{
	int i = 0;

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (isdigit(token[i]) == 0)
			return (1);
	}
	return (0);
}
