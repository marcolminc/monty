#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: Monty Bytecode line number currently being executed
 *
 * Return: nothing
 */
void add(stack_t **stack, const unsigned int line_number)
{
	stack_t *addend1, *addend2;

	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	addend1 = *stack, addend2 = (*stack)->prev;
	addend2->n += addend1->n;
	pop(stack, line_number);
}


/**
 * sub - subtracts the top element of the stack from the second top element of
 * the stack
 * @stack: the stack
 * @line_number: Monty Bytecode line number currently being executed
 *
 * Return: nothing
 */
void sub(stack_t **stack, const unsigned int line_number)
{
	stack_t *subtrahend, *minuend;

	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	subtrahend = *stack, minuend = (*stack)->prev;
	minuend->n = minuend->n - subtrahend->n;
	pop(stack, line_number);
}
