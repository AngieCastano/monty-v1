#include "monty.h"
/**
 * main - The main of our program
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 in succes 1 if fails
**/
int main(int argc, char *argv[])
{
	FILE *file_name;
	char single_line[150];
	char *token;
	int i = 1, t;
	/*
	*	instruction_t func_dict[] = {{"push", funct_push}, {"pall", funct_pall}
	*				     {"pint", funt_pint}, (NULL, NULL)};
	**/
	if (argc < 2)
		printf("USAGE: monty file\n"), exit (EXIT_FAILURE);
	file_name =  fopen(argv[1], "r");
	if (file_name == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	for(;fgets(single_line, 150, file_name) != NULL; i++)
	{
		token = strtok(single_line, " \n");
		for(t = 0; token != NULL; t++)
		{
			printf("line %i: token %i: %s\n", i, t, token);
			token = strtok(NULL, "\n");
		}
	}
	fclose(file_name); return (0);
}
