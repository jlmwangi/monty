#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to previous element of stack
 * @next: points to next element of stack
 *
 * Description: doubly linked list node structure for
 * stack, queues, LIFO, FIFO
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
 * Description: opcode and its function for
 * stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct glo_s - global and functions
 * @fd: file descriptor
 * @input: line to read
 */
typedef struct glo_s
{
	FILE *fd;
	char *input;
} glo_t;

extern glo_t global;
extern int value;

int main(int ac, char *av[]);
void read_file(char *av);
int handle_opcode(stack_t **stack, char *arg, char *item, int c);

void push_(stack_t **stack, unsigned int line_number);
void pall_(stack_t **stack, unsigned int ln);
void swap_(stack_t **stack, unsigned int line_number);
void pint_(stack_t **stack, unsigned int line_number);
void add_(stack_t **stack, unsigned int line_number);
void pop_(stack_t **stack, unsigned int line_number);
void sub_t(stack_t **stack, unsigned int line_number);
void mul_t(stack_t **stack, unsigned int line_number);
void div_d(stack_t **stack, unsigned int line_number);
void mod_(stack_t **stack, unsigned int line_number);
void p_str(stack_t **stack, unsigned int line_number);
void p_char(stack_t **stack, unsigned int line_number);
stack_t *newnode(int n);
void free_list(stack_t *stack);

void error_push(FILE *fd, char *input, stack_t *stack, int c);
void _error(FILE *fd, char *input, stack_t *stack, char *s, int i);

void stack_clean(stack_t **stack);
int is_digit(char *s);

#endif
