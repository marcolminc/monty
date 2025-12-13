#include "monty.h"


/**
 * _getline - reads an entire line from the input stream (file), up to,
 * including a newline character
 * @lineptr: the buffer that should store the read line, null-terminated
 * (including newline character, if found)
 * @n: size of the buffer storing the read line (current)
 * @stream: the source (input/file) where lines are read from
 *
 * Return: number of characters read, including the new line character, but
 * excluding the terminating null byte. This value can be used to handle
 * embedded null bytes in the line read.
 *
 * - on failure (like EOF before reading any bytes), it returns - 1
 *
 * - If *lineptr is set to NULL before the call, then getline() will allocate a
 * buffer for storing the line.   This  buffer  should  be freed by the user
 * program even if getline() failed.
 *
 * - Alternatively,  before calling getline(), *lineptr can contain a pointer
 * to a malloc(3)-allocated buffer *n bytes in size.
 *
 * - If the buffer is not large enough to hold the line, getline() resizes it
 * with realloc(3) (project restricted), updating *lineptr and *n as necessary.
 *
 * In either case, on a successful call, *lineptr and *n will be updated to
 * reflect the buffer address  and  allocated  size  respectively
 *
 * ERRORS
 * - EINVAL Bad arguments (n or lineptr is NULL, or stream is not valid).
 * - ENOMEM Allocation or reallocation of the line buffer failed.
 */
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	size_t pos;

	pos = 0;
	if (!*lineptr)
		*lineptr = buff_init(n);
	while (true)
	{
		c = (char)fgetc(stream);
		if (c == EOF)
		{
			if (!pos)
				return (-1);
			(*lineptr)[pos] = '\0';
			return (pos);
		}
		if (pos >= *n - 1)
		{
			*lineptr = _realloc(*lineptr, *n, (*n + BUFF_SIZE));
			*n += BUFF_SIZE;
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
		{
			(*lineptr)[pos] = '\0';
			return (pos);
		}
	}
}


/**
 * buff_init - initializes a block of memory for storing a string of characters
 * @n: number of bytes that should be allocated for the buffer
 * Return: buffer, if successful, NULL otherwise.
 */
char *buff_init(const size_t *n)
{
	char *buf;

	buf = malloc(*n * sizeof(*buf));
	if (!buf)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (buf);
}


/**
 * _realloc - reallocates a memory block, using malloc() and free()
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * @ptr: old memory block
 *
 * Return: new memory block, NULL or ptr otherwise
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *res;

	res = NULL;
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new_size);
	if (!res)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!ptr)
		return (res);
	for (i = 0; i < old_size && i < new_size; i++)
		*(res + i) = *((char *)ptr + i);
	free(ptr);
	return (res);
}

