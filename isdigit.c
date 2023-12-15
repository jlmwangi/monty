#include "monty.h"
/**
 * stack_clean - frees stacks
 * @stack: pointer to pointer to stack_t
 */
void stack_clean(stack_t **stack)
{
	stack_t *new = *stack;

	for (; new; new = *stack)
	{
		*stack = (*stack)->next;
		free(new);
	}
	fclose(global.fd);
	free(global.input);
}

/**
 * is_digit - checks for digits
 * @s: pointer to string
 *
 * Return: int
 */
int is_digit(char *s)
{
	char *c = s;

	if (s == NULL)
		return (0);
	if (*c == '-')
		c++;

	for (; *c != '\0'; c++)
	{
		if ((*c < '0' || *c > '9'))
		{
			return (0);
		}
	}
	return (1);
}
