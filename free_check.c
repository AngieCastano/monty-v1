#include "monty.h"
/**
 * if_free_fails - checks if malloc fails
 * @pointer: pointer to check
 **/
void if_free_fails(void *pointer)
{
	if (pointer == NULL)
	{
		free(pointer);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * free_tokenized - frees tokenized
 * @tokenized: double pointer that contains tokens from single_line
 */
void free_tokenized(char **tokenized)
{
	int f = 0;

	for (f = 0; tokenized[f] != NULL; f++)
		free(tokenized[f]);
	free(tokenized);
}
/**
 * free_list - frees the list
 * @head: head of the list
 **/
void free_list(stack_t **head)
{
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
/**
 * check_empty - aja
 * @head: head of dllist
 * @tokenized: string tokens
 * @file: file opened
 * @line_num: number of lines read
 * @it: index dic
 **/
void check_empty(stack_t **head, char **tokenized, FILE *file, int line_num,
		 int it)
{
	if (!tokenized[1] && it == 0)
	{
		free_list(head);
		free_tokenized(tokenized);
		fclose(file);
		printf("L%i: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
}
