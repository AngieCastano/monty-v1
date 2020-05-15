#include "monty.h"
/**
 * check_opcode - checks opcodes
 * @tokenized: double pointer to single_line
 * @head: head to the structura
 * @line_num: number line
 * @file: file name
 **/
void check_opcode(char **tokenized, stack_t **head, unsigned int line_num,
		  FILE **file)
{
	int it = 0;
	char *copy = tokenized[0];
	instruction_t func_dict[] = {{"push", funct_push}, {"pall", funct_pall},
				     {"pint", funct_pint}, {"pop", funct_pop},
				     {"swap", f_swap}, {"add", funct_add},
				     {"nop", funct_nop}, {NULL, NULL}};

	if (tokenized[1] && strcmp(tokenized[0], "push") == 0)
	{
		if (check_digits(tokenized[1]) == 0)
			ext_n = atoi(tokenized[1]);
		else
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_num);
			free_list(head);
			free_tokenized(tokenized);
			fclose(*file);
			exit(EXIT_FAILURE);
		}
	}
	for (it = 0; func_dict[it].opcode; it++)
	{
		if (strcmp(tokenized[0], func_dict[it].opcode) == 0)
		{
			check_empty(head, tokenized, *file, line_num, it);
			func_dict[it].f(head, line_num);
			return;
		}
	}
	if (func_dict[it].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, copy);
		free_list(head);
		free_tokenized(tokenized);
		fclose(*file);
		exit(EXIT_FAILURE);
	}
}
