#ifndef MONTY_H
#define MONTY_H

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/* definitions */
#define BUFF_SIZE 1024


/* data structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*extern instruction_t *op_tbl[17];*/
typedef void (*Operation)(stack_t **, unsigned int);


/* prototypes */
char *buff_init(const size_t *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strdup(char *);
char *parse_opcode(char *);
FILE *open_file(int, const char **);
void _perror(size_t, const char *);
void cleanup(char *, stack_t **, FILE *, instruction_t **, size_t);

instruction_t **init_op_tbl(void);
int is_full_int(const char *, int *);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void free_stack(stack_t **);
void free_op_tbl(instruction_t **, unsigned int);


#endif /*MONTY_H*/

