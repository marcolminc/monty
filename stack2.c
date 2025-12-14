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
