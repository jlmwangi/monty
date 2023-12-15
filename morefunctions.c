#include "monty.h"
/**
 * p_str - print a string
 * @stack: pointer to pointer to stack
 * @line_number: number of lines
 */
void p_str(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	new = *stack;

	while (new && new->n)
	{
		if (new->n > 127 || new->n < 32)
			break;
		printf("%c", new->n);
		new = new->next;
	}
	putchar(10);
}

/**
 * p_char - prints character
 * @stack: pointer to pointer to stack
 * @line_number: unsigned int
 */
void p_char(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: stack empty\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n > 127 || n < 0)
	{
		dprintf(STDERR_FILENO, "L%d: value out of range\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	putchar(n);
	putchar(10);
}

/**
 * mul_t - multiplies top two elements
 * @stack: pointer to pointer to a stack_t
 * @line_number: unsigned int
 */
void mul_t(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *curr = NULL;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	m = curr->next->n * curr->n;
	pop_(stack, line_number);
	curr->next->n = m;
}

/**
 * div_d - divides two numbers
 * @stack: pointer to pointer to stack_t
 * @line_number: number of lines
 */
void div_d(stack_t **stack, unsigned int line_number)
{
	int d = 0;
	stack_t *curr = NULL;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	d = curr->next->n / curr->n;
	curr->next->n = d;
	pop_(stack, line_number);
}

/**
 * mod_ - calculates modulus
 * @stack: pointer to pointer to stack
 * @line_number: unsigned int
 */
void mod_(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = NULL;
	int md = 0;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		stack_clean(stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	md = curr->next->n % curr->n;
	curr->next->n = md;
	pop_(stack, line_number);
}
