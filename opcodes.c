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
 * @n: line number of the file when fails
 **/
void funct_pint(stack_t **head, unsigned int n)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (**head).n);
}
/**
 * funct_pop - emoves the top element of the stack.
 * @head: head of the list to remove from the stack
 * @n: line number of the file when fails
 **/
void funct_pop(stack_t **head, unsigned int n)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	if (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
		return;
	}
	free(*head);
	*head = NULL;
}
/**
 * funct_pop - swap two last stack elements.
 * @head: head of the list to remove from the stack
 * @n: line number of the file when fails
 **/
void f_swap(stack_t **head, unsigned int n)
{
	stack_t *aux;
	(void) n;

	if  (!*head || !head)
	{
		fprintf(stderr,
			"L%i: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (!(**head).next)
	{
		fprintf(stderr,
			"L%i: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (!(*head)->next->next && (*head && head))
	{
		(**head).prev = (**head).next;
		(**head).next = NULL;
		*head = (**head).prev;
		(**head).next = (**head).prev;
		(**head).prev = NULL;
		return;
	}
	if ((**head).next && (*head && head))
	{
		aux = *head;
		*head = aux->next;
		(**head).prev = NULL;
		aux->next = (**head).next;
		aux->prev = *head;
		(**head).next = aux;
		aux = (*aux).next;
		aux->prev = (**head).next;
		return;
	}
}
