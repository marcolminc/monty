#include "monty.h"


/**
 * create_node - creates a new stack node
 * Return: a new stack node
 */
stack_t *create_node()
{
	stack_t *node;

	node = malloc(sizeof(*node));
	if (!node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->next = node->prev = NULL;
	return (node);
}


/**
 * push - pushes an element to the stack
 * @stack: reference to the stack
 * @line_number: number of the line currently being executed (starting from 1)
 *
 * Return: nothing
 */
void push(stack_t **stack, const unsigned int line_number)
{
	int value;
	stack_t *new;

	if (arg && is_full_int(arg, &value))
	{
		if (!*stack)
		{
			*stack = create_node();
			(*stack)->n = value;
		}
		else
		{
			new = create_node();
			new->n = value;
			(*stack)->next = new;
			new->prev = *stack;

			*stack = new;
		}
		return;
	}
	printf("L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}


/**
 * pall - prints all elements currently in the stack
 * @stack: the stack whose elements should be printed
 * @line_number: number of a line of Monty bytecodes currently being executed
 *
 * Return: nothing
 */
void pall(stack_t **stack, const unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!*stack)
	{
		printf("Error: stack underflow\n");
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}


/**
 * free_stack - frees stack data structure
 * @stack: the stack
 *
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->prev;
			free(temp);
		}
		*stack = NULL;
	}
}

