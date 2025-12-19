#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: the stack
 * @line_number: Monty Bytecode line number currently being executed
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;
	(void)line_number;

	if (*stack && (*stack)->prev)
	{
		top = bottom = *stack;
		while (bottom->prev)
			bottom = bottom->prev;
		*stack = top->prev, (*stack)->next = NULL;
		bottom->prev = top, top->next = bottom;
		top->prev = NULL;
	}
}


/**
 * rotr - rotates the stack to the bottom
 * @stack: the stack
 * @line_number: Monty Bytecode line number currently being executed
 *
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom;

	(void)line_number;
	if (*stack && (*stack)->prev)
	{
		bottom = *stack;
		while (bottom->prev)
			bottom = bottom->prev;
		bottom->next->prev = NULL;
		bottom->next = NULL;
		bottom->prev = *stack;
		(*stack)->next = bottom;
		*stack = bottom;
	}
}
