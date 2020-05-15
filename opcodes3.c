#include "monty.h"
/**
 * f_mod - adds the top two elements of the stack.
 * @head: head of the list
 * @n: line number of the file
 */
void f_mod(stack_t **head, unsigned int n)
{
	if  (!*head || !head)
	{
		fprintf(stderr,
			"L%i: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (!(**head).next)
	{
		fprintf(stderr,
			"L%i: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if ((**head).n == 0)
	{
		fprintf(stderr,
			"L%i: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	if ((**head).next && (*head && head))
	{
		*head = (**head).next;
		(**head).n %= (*head)->prev->n;
		free((*head)->prev);
	}
}
