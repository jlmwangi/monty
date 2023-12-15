#include "monty.h"
#include <stdio.h>

/**
 * _error - error handler
 * @fd: file descriptor
 * @input: pointer to string
 * @stack: pointer to stack
 * @s: pointer to string
 * @i: integer
 */
void _error(FILE *fd, char *input, stack_t *stack, char *s, int i)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", i, s);
	fclose(fd);
	free(input);
	free_list(stack);
	exit(EXIT_FAILURE);
}
/**
 * error_push - handle push error
 * @fd: file descriptor
 * @stack: pointer to a stack_t
 * @input: pointer to string
 * @c: integer
 */
void error_push(FILE *fd, char *input, stack_t *stack, int c)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", c);
	fclose(fd);
	free(input);
	free_list(stack);
	exit(EXIT_FAILURE);
}
