#include "monty.h"


/**
 * free_op_tbl - frees the operations table memory block
 * @tbl: the operations table
 * @size: size of the operations table
 *
 * Return: nothing
 */
void free_op_tbl(instruction_t **tbl, const unsigned int size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		free(tbl[i]->opcode);
		free(tbl[i]);
	}
	free(tbl);
}



