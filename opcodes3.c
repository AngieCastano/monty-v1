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
/**
 * f_pchar - adds the top two elements of the stack.
 * @head: head of the list
 * @n: line number of the file
 */
void f_pchar(stack_t **head, unsigned int n)
{
	(void) head;
	(void) n;

	if  (!*head || !head)
	{
		fprintf(stderr,
			"L%i: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if ((**head).n >= 0 && (**head).n < 128)
		printf("%c\n", abs((**head).n));
	else
	{
		fprintf(stderr,
			"L%i: can't pchar, value out of range", n);
		exit(EXIT_FAILURE);
	}
}
