#include "monty.h"
/**
 * funct_push - adds an integer to a double linked list
 * @head: head of the list to modify
 * @n: number to add
 **/
void funct_push (stack_t **head, unsigned int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		printf("Error: malloc failed\n"); exit (EXIT_FAILURE);
	(*new).n = n;
	(*new).next = *head;
	(*new).prev = NULL;

	if (*head)
		(*head)->prev = new;
	*head = new;
}
/**
 * funct_pall - prints the whole list
 * @head: head of the list list to print
 * @n: unused variable
 **/
void funct_pall(stack_t **head, unsigned int n)
{
	size_t i = 0;
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
void funct_pint(stack_t **head, unsigned int n)
{
	printf("%d\n", (**head).n);
}
