#include "monty.h"


/**
 * _perror - custom function for printing opcode-related error
 * @nline: number of Monty bytecodes line currently being executed
 * @tok: the opcode (supposedly) being worked on
 *
 * Return: nothing
 */
void _perror(const size_t nline, const char *tok)
{
	fprintf(stderr, "L%lu: Unknown instruction %s\n", nline, tok);
}

void cleanup(char *line, stack_t **stack, FILE *fp, instruction_t **op_tbl,
	size_t op_tbl_size)
{
	if (line)
		free(line);
	free_stack(stack);
	free_op_tbl(op_tbl, op_tbl_size);
	fclose(fp);
}


/**
 * init_op_tbl - initializes the operations table
 *
 * Return: the operations table
 */
instruction_t **init_op_tbl(void)
{
	size_t i;
	instruction_t *inst, **tbl;
	char *opcodes[] = {
		"push", "pall"
	};

	const Operation f_arr[] = {
		push, pall
	};

	tbl = malloc((sizeof(f_arr) / sizeof(f_arr[0])) * sizeof(instruction_t *));
	if (!tbl)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < sizeof(f_arr) / sizeof(f_arr[0]); i++)
	{
		inst = malloc(sizeof(*inst));
		if (!inst)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		inst->opcode = _strdup(opcodes[i]);
		inst->f = f_arr[i];
		tbl[i] = inst;
	}
	return (tbl);
}

