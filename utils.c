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
	fprintf(stderr, "L%lu: unknown instruction %s\n", nline, tok);
}


/**
 * cleanup - clears and returns resources
 * @line: Monty Bytecode line currently being executed
 * @stack: the stack
 * @fp: Monty Bytecode file pointer
 * @op_tbl: the opcodes table
 * @op_tbl_size: size of op_tbl
 *
 * Return: nothing
 */
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
		"push", "pall", "pint", "pop", "swap", "add", "nop", "sub",
		"div", "mul", "mod"
	};

	const Operation f_arr[] = {
		push, pall, pint, pop, swap, add, nop, sub, _div, mul, mod
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


/**
 * is_full_int - converts a string token to integer making sure it's
 * all a number
 * @str: the token (str) to convert to integer
 * @num: the variable to store the (converted) integer to
 *
 * Return: (int) 1 if the string token is whole converted to integer, 0
 * otherwise
 */
int is_full_int(const char *str, int *num)
{
	int count;
	const signed int chars_assigned = sscanf(str, "%d%n", num, &count);

	if (chars_assigned != 1)
		return (0);
	if (count == (int)strlen(str))
		return (1);
	return (0);
}


/**
 * open_file - opens a file passed to the monty interpreter program
 * @argc: number of CLI arguments passed
 * @argv: CLI args's vector
 *
 * Return: file pointer upon success
 */
FILE *open_file(const int argc, const char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file HoLbErToN\n");
		exit(EXIT_FAILURE);
	}
	return (fp);
}

