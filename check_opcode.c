#include "monty.h"
/**
 * check_opcode - checks opcodes
 * @tokenized: double pointer to single_line
 * @head: head to the structura
 * @line_num: number line
 * @file: file name
 **/
void check_opcode(char **tokenized, stack_t **head, int line_num, FILE **file)
{
	int it = 0, n = 5;
	instruction_t func_dict[] = {{"push", funct_push}, {"pall", funct_pall},
				     {"pint", funct_pint}, {NULL, NULL}};

	if (tokenized[1])
	{
		if (check_digits(tokenized[1]) == 0)
			ext_n = atoi(tokenized[1]);
		else
		{
			printf("L%i: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	for (it = 0; func_dict[it].opcode; it++)
	{
		if (strcmp(tokenized[0], func_dict[it].opcode) == 0)
		{
			check_empty(head, tokenized, *file, line_num, it);
			func_dict[it].f(head, n);
			return;
		}
	}
	if (func_dict[it].opcode == NULL)
	{
		printf("L%i: unknown instruction %s\n", line_num, tokenized[0]);
		free_list(head);
		free_tokenized(tokenized);
		fclose(*file);
		exit(EXIT_FAILURE);
	}
}
