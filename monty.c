#include "monty.h"
int ext_n;
/**
 * main - The main of our program
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 in succes 1 if fails
**/
int main(int argc, char *argv[])
{
	FILE *file_name;
	char single_line[1500];
	char **tokenized;
	unsigned int i = 1;
	stack_t *head = NULL;

	ext_n = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name =  fopen(argv[1], "r");
	if (file_name == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; fgets(single_line, 1500, file_name) != NULL; i++)
	{
		tokenized = tokenizer(single_line);
		if (tokenized[0] == NULL || tokenized[0][0] == '#')
		{
			free(tokenized);
			continue;
		}
		check_opcode(tokenized, &head, i, &file_name);
		free_tokenized(tokenized);
	}
	free_list(&head);
	head = NULL;
	fclose(file_name);
	return (0);
}
