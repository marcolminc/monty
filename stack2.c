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


/**
 * nop - doesn't do anything
 * @stack: the stack data structure
 * @line_number: Monty Bytecode line number currently being executed
 */
void nop(stack_t **stack, const unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * stack - swaps mode to stack
 * @stack: the data structure whose mode should be swapped
 * @line_number: Monty Bytecode line number currently being executed
 *
 * Return: Nothing
 */
void stack(stack_t **stack, const unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = STACK;
}


/**
 * queue - swaps mode to stack
 * @stack: the data structure whose mode should be swapped
 * @line_number: Monty Bytecode line number currently being executed
 *
 * Return: Nothing
 */
void queue(stack_t **stack, const unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = QUEUE;
}
