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
	char **tokenized;
	int i = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name =  fopen(argv[1], "r");
	if (file_name == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; fgets(single_line, 150, file_name) != NULL; i++)
	{
		tokenized = tokenizer(single_line);
		check_opcode(tokenized, &head, i, &file_name);
		free_tokenized(tokenized);
	}
	free_list(&head);
	head = NULL;
	fclose(file_name);
	return (0);
}
