#include "monty.h"


/**
 * parse_opcode - finds out if a supposed opcode is indeed in the
 * operations table
 * @tok: supposed opcode string
 *
 * Return: definite opcode if in the operations table, null otherwise
 */
char *parse_opcode(char *tok)
{
	size_t i;
	char *opcodes[9] = {
		"push", "pall", "pint", "pop", "swap", "add", "nop", "sub",
		"div"
	};

	if (tok)
		for (i = 0; i < 9; i++)
			if (strcmp(opcodes[i], tok) == 0)
				return (tok);
	return (NULL);
}


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

