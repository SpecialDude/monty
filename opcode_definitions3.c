#include "monty.h"

/**
 * pchar - Prints the top element of the stack
 *
 * @stack: Stack
 * @line_number: Instruction Line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - Prints elements of a stack as str
 *
 * @stack: Stack
 * @line_number: Instruction Line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = (*stack);

	line_number += 1;

	while (node && node->n != 0 && !(node->n > 127 || node->n < 0))
	{
		putchar(node->n);
		node = node->next;
	}
	putchar('\n');
}

/**
 * rotl - Rotates the stack to the top.
 *
 * @stack: Stack
 * @line_number: Instruction codes line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *top, *new_top;

	if (!((*stack) && (*stack)->next))
		return;

	node = (*stack);
	top = (*stack);

	new_top = (*stack)->next;

	while (node && node->next)
		node = node->next;

	top->prev = node;
	node->next = top;
	top->next = NULL;
	new_top->prev = NULL;
	(*stack) = new_top;

	line_number++;
}

/**
 * rotr - Rotates the stack to the bottom.
 *
 * @stack: Stack
 * @line_number: Instruction codes line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!((*stack) && (*stack)->next))
		return;

	node = (*stack);

	while (node && node->next)
		node = node->next;

	node->prev->next = NULL;

	node->prev = (*stack)->prev;
	node->next = (*stack);

	(*stack)->prev = node;
	(*stack) = node;

	line_number++;
}
