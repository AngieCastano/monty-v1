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
	char single_line[150], **tokenized;
//	instruction_t func_dict[] = {{"push", funct_push}, {"pall", funct_pall}
//				     {"pint", funt_pint}, (NULL, NULL)};
	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	file_name =  fopen(argv[1], "r");
	while(!feof(file_name))
	{
		fgets(single_line, 150, file_name);
		tokenized = tokenizer(single_line);
		for (int i = 0; tokenized[0]; i++)
		{
			printf("%s\n", tokenized[i])
		}
	}
	fclose(file_name);
	return (0);
}
