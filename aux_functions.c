#include "monty.h"
/**
 * _strdup - generates a string
 * @str: string to recive
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *copy = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
	}
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		copy[i] = str[i];
	}
	copy[i] = '\0';
	return (copy);
}
/**
 * _strlen - prints the length of a string
 * @s: the string to measure
 *
 * Return: No returning
 */
int _strlen(char *s)
{
	int counter;

	for (counter = 0; s[counter] != '\0'; counter++)
	{}
	return (counter);
}
