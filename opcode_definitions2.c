#include "monty.h"

/**
 * add - Adds the top 2 element in a stack
 *
 * @stack: Stack
 * @line_number: Instruction Line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	(*stack)->next->n = sum;

	pop(stack, line_number);
}
