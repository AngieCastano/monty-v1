#ifndef MONTY_H
#define MONTY_H
#define DELIMITER " \n\t"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int ext_n;
char **tokenizer(char *line);
char *_strdup(char *str);
int _strlen(char *s);
void funct_push(stack_t **head, unsigned int n);
void funct_pall(stack_t **head, unsigned int n);
void funct_pint(stack_t **head, unsigned int n);
void check_opcode(char **tokenized, stack_t **head, unsigned int line_number,
		  FILE **f);
void if_free_fails(void *pointer);
void free_tokenized(char **tokenized);
void free_list(stack_t **head);
void check_empty(stack_t **head, char **tokenized, FILE *file, int line_num,
		 int it);
int check_digits(char *token);
void funct_pop(stack_t **head, unsigned int n);
void f_swap(stack_t **head, unsigned int n);
void funct_add(stack_t **head, unsigned int n);
void funct_nop(stack_t **head, unsigned int n);
void funct_sub(stack_t **head, unsigned int n);
void f_div(stack_t **head, unsigned int n);
void f_mul(stack_t **head, unsigned int n);
void f_mod(stack_t **head, unsigned int n);
void f_pchar(stack_t **head, unsigned int n);
void f_pstr(stack_t **head, unsigned int n);

#endif
