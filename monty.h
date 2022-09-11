#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<fcntl.h>

#define LINE_READ_BUF 1024
#define WORD_BUF 512
#define LINE_WORDS_BUF 128

/**
 * struct stack_s - doubly linked list
 * representation of a stack (or queue)
 *
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
 *
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



extern stack_t *stack;
extern char **instruction_args;
extern int instruction_args_count;

void free_stack(stack_t *stack);
void free_memory(char **ptr);
void *malloc_or_exit(size_t size);
void *realloc_or_exit(void *ptr, size_t size, size_t new_size);

void A_sh_toggle(short *value);
void A_sh_print(char **str);
int is_integer(char *str);

char **parse_line(char *line);
void execute(char *line, int line_number);
int is_NII(char *opcode);
int is_comment(char *line);

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divop(stack_t **stack, unsigned int line_number);
void mulop(stack_t **stack, unsigned int line_number);
void modop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
