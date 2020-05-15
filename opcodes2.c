#include "monty.h"
/**
 * funct_add - adds the top two elements of the stack.
 * @head: head of the list
 * @n: line number of the file
 */
void funct_add(stack_t **head, unsigned int n)
{
	if  (!*head || !head)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (!(**head).next)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if ((**head).next && (*head && head))
	{
		*head = (**head).next;
		(**head).n += (*head)->prev->n;
		free((*head)->prev);
	}
}
/**
 * funct_nop - does nothing
 * @head: head of the list
 * @n: line number of the file
 */
void funct_nop(stack_t **head, unsigned int n)
{
	(void) head;
	(void) n;
}
/**
 * funct_sub - adds the top two elements of the stack.
 * @head: head of the list
 * @n: line number of the file
 */
void funct_sub(stack_t **head, unsigned int n)
{
	if  (!*head || !head)
	{
		fprintf(stderr,
			"L%i: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (!(**head).next)
	{
		fprintf(stderr,
			"L%i: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if ((**head).next && (*head && head))
	{
		*head = (**head).next;
		(**head).n -= (*head)->prev->n;
		free((*head)->prev);
	}
}
