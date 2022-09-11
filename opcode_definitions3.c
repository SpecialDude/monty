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
