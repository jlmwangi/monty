#include "monty.h"
#include <stdio.h>

/**
 * add_ - adds two numbers
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int
 */
void add_(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *curr = NULL;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	sum = curr->next->n + curr->n;
	curr->next->n = sum;
	pop_(stack, line_number);
}

/**
 * sub_t - subtract top element from second
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int
 */
void sub_t(stack_t **stack, unsigned int line_number)
{
	int st = 0;
	stack_t *curr = *stack;

	if (!curr || !curr->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	st = curr->next->n - curr->n;
	curr->next->n = st;
	pop_(stack, line_number);
}

/**
 * pop_ - removes top element
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int
 */
void pop_(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = NULL;

	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}

	curr = *stack;

	*stack = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	free(curr);
}

/**
 * swap_ - swaps top two elements
 * @stack: pointer to pointer to stack
 * @line_number: unsigned int
 */
void swap_(stack_t **stack, unsigned int line_number)
{
	int temp = 0;
	stack_t *curr = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	temp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = temp;
}

/**
 * nop_ - void function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int
 */
void nop_(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
