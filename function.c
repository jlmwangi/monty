#include "monty.h"
#include <stdio.h>

int value;
/**
 * push_ - insert item
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int
 */
void push_(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = newnode(value);
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall_ - prints all elements
 * @stack: pointer to pointer to stack_t
 * @ln: unsigned int
 */
void pall_(stack_t **stack, unsigned int ln)
{
	stack_t *new = NULL;
	(void)ln;

	new = *stack;

	while (new)
	{
		dprintf(STDOUT_FILENO, "%d\n", new->n);
		new = new->next;
	}
}

/**
 * pint_ - print top value
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int
 */
void pint_(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * newnode - creates new node
 * @n: value
 *
 * Return: stack_t
 */
stack_t *newnode(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

/**
 * free_list - frees a lsit
 * @stack: pointer to stack_t
 */
void free_list(stack_t *stack)
{
	stack_t *curr = NULL;

	curr = stack;
	if (curr)
	{
		free_list(curr->next);
		free(curr);
	}
}
