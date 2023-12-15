#include "monty.h"

glo_t global = {NULL, NULL};

/**
 * main - program entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: int
 */
int main(int ac, char *av[])
{
	if (ac == 2)
		read_file(av[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * handle_opcode - handles opcode
 * @stack: stack or queue
 * @arg: pointer to string
 * @item: pointer to string
 * @c: integer
 *
 * Return: int
 */
int handle_opcode(stack_t **stack, char *arg, char *item, int c)
{
	int n = 0;

	instruction_t op[] = {
		{"push", push_},
		{"pall", pall_},
		{"swap", swap_},
		{"pint", pint_},
		{"add", add_},
		{"pop", pop_},
		{"sub", sub_t},
		{"mul", mul_t},
		{"div", div_d},
		{"mod", mod_},
		{"pstr", p_str},
		{"pchar", p_char},
		{"nop", nop_},
		{NULL, NULL}
	};

	while (op[n].opcode)
	{
		if (!strcmp(arg, op[n].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (is_digit(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			op[n].f(stack, (unsigned int)c);
			break;
		}
		n++;
	}
	if (!op[n].opcode)
		return (3);

	return (0);
}
/**
 * read_file - reads file
 * @av: pointer to string
 */
void read_file(char *av)
{
	char *args = NULL, *item = NULL;
	size_t buf = 0;
	stack_t *stack = NULL;
	int res = 0, n = 0;

	global.fd = fopen(av, "r");
	if (global.fd != NULL)
	{
		while (getline(&global.input, &buf, global.fd) != -1)
		{
			n++;
			args = strtok(global.input, " \n\r\t");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#')
				continue;
			item = strtok(NULL, " \n\t\r");
			res = handle_opcode(&stack, args, item, n);
			if (res == 1)
				error_push(global.fd, global.input, stack, n);
			else if (res == 2)
				_error(global.fd, global.input, stack, args, n);
		}
		free(global.input);
		free_list(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av);
		exit(EXIT_FAILURE);
	}
}
