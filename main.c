#include <string.h>

#include "monty.h"


/**
 * main - entry point for monty program
 * @argc: number of CLI arguments passed
 * @argv: CLI arguments vector
 *
 * Return: 0 for success
 */

int main(const int argc, char *argv[])
{
	FILE *fp;
	char *line, *opcode;
	size_t size, nread, nline, i, in_tbl;
	stack_t *stack;
	instruction_t **op_tbl;

	fp = open_file(argc, (const char **)argv), op_tbl = init_op_tbl();
	size = BUFF_SIZE, line = NULL, nline = 0, stack = NULL;
	while (((nread = _getline(&line, &size, fp))) && nread != (size_t)-1)
	{
		nline++;
		in_tbl = 0;
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			for (i = 0; i < 4; i++)
			{
				if (strcmp(op_tbl[i]->opcode, opcode) == 0)
				{
					in_tbl++;
					op_tbl[i]->f(&stack, nline);
				}
			}
		}
		if (opcode && !in_tbl)
		{
			_perror(nline, opcode);
			cleanup(line, &stack, fp, op_tbl, 4);
			exit(EXIT_FAILURE);
		}
	}
	cleanup(line, &stack, fp, op_tbl, 4);
	exit(EXIT_SUCCESS);
}

