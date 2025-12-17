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



