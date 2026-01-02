# 0x19.C - Stacks, Queues - LIFO, FIFO
### Requirements
* Allowed editors: `vi, vim emacs`
* compilation options: -wall -Werror -Wextra -pedantic -std=c89
* code should use Betty style
* max of one global variable
* no more than 5 functions per file
* Allowed to use C standard library
* prototypes should be in `monty.h`, include-guarded
* do the tasks in the order shown in the project
* allowed to use `malloc` and `free` and not allowed to use any other function from `man malloc`


### Data structures
```C
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

```

### Compilation
* code should be compiled this way:
    ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
    ```
* Any output must be printed on *stdout*
* Any error messages must be printed on *stderr*


### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```bash
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
push 3$
pall    $
push 4$
push 5    $
push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```bash
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
push 3$
pall    $
$
$
$
push 4$
$
push 5    $
push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

#### The monty program

* Usage: monty file
    * where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
* If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
    * where <file> is the name of the file
* If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
    * where is the line number where the instruction appears.
    * Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
    * it executed properly every line of the file
    * it finds an error in the file
    * an error occurred
* If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
* You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)


### Tasks
1. 0 - push, pall: implement the `push` and `pall` opcodes.
    * `push` pushes an element to the stack: push <int>
    * `pall` prints all the values on the stack, starting from top of the stack
2. 1 - pint: implement the pint opcode
3. 2 - pop: implement the pop opcode
4. 3 - swap: implement the swap opcode
5. 4 - add: implement the add opcode
6. 5 - nop: implement the nop opcode
7. 6 - sub: implement the sub opcode
8. 7 - div: implement the div opcode
9. 8 - mul: implement the mul opcode
10. 9 - mod: implement the mod opcode
11. 10 - comments: implement the capability of commenting
12. 11 - pchar: implement the pchar opcode
13. 12 - pstr: implement the pstr opcode
14. 13 - rotl: implement the rotl opcode
15. 14 - rotr: implement the rotr opcode
16. 15 - stack, queue: implement the stack and queue opcodes

