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
		printf("Error: malloc failed\n");
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
