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
	int it = 0;
	int n = 0;
	instruction_t func_dict[] = {{"push", funct_push}, {"pall", funct_pall},
				     {"pint", funct_pint}, {NULL, NULL}};

	for (it = 0; func_dict[it].opcode; it++)
	{
		if (strcmp(tokenized[0], func_dict[it].opcode) == 0)
		{
			if (tokenized[1])
				n = abs(atoi(tokenized[1]));
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
