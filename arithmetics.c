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

