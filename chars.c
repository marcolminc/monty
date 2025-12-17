#include "monty.h"


void pchar(stack_t ** stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}


/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the stack
 * @line_number: number of Monty Bytecode line currently being executed
 *
 * Return: nothing
 */
void pstr(stack_t ** stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack)
	{
		tmp = *stack;
		do
		{
			if (tmp->n <= 0 || tmp->n > 127)
				break;
			printf("%c", tmp->n);
			tmp = tmp->prev;
		} while (tmp);
	}
	printf("\n");
}
