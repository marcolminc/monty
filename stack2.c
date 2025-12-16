#include "monty.h"


/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: number of Monty Bytecode line currently being executed
 *
 * Return: nothing
 */
void pop(stack_t **stack, const unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->prev;
	free(tmp);
	if (*stack)
		(*stack)->next = NULL;
}


/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: number of the Monty Bytecode line currently being executed
 *
 * Return: nothing
 */
void swap(stack_t **stack, const unsigned int line_number)
{
	stack_t *l, *r;

	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	l = *stack, r = (*stack)->prev;
	l->prev = r->prev;
	r->next = NULL;

	if (r->prev)
		r->prev->next = l;
	r->prev =  l;
	l->next = r;
	*stack = r;
}
