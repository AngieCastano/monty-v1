#include "monty.h"
/**
 * funct_push - adds an integer to a double linked list
 * @head: head of the list to modify
 * @n: number to add
 **/
void funct_push(stack_t **head, unsigned int n)
{
	stack_t *new_node = NULL;
	(void) n;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_list(head);
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = ext_n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head)
	{
		(*head)->prev = new_node;
		new_node->next = *head;
	}
	*head = new_node;
}
/**
 * funct_pall - prints the whole list
 * @head: head of the list list to print
 * @n: unused variable
 **/
void funct_pall(stack_t **head, unsigned int __attribute__((unused)) n)
{
	int i = 0;
	stack_t *aux = *head;

	for (; aux; i++)
	{
		printf("%d\n", (*aux).n);
		aux = (*aux).next;
	}
}
/**
 * funct_pint - prints the integer at the top of the list
 * @head: head of the list list to print
 * @n: unused variable
 **/
void funct_pint(stack_t **head, unsigned int __attribute__((unused)) n)
{
	printf("%d\n", (**head).n);
}
