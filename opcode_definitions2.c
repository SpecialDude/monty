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


/**
 * sub - Subtracts the top 2 element in a stack
 *
 * @stack: Stack
 * @line_number: Instruction Line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;

	(*stack)->next->n = diff;

	pop(stack, line_number);
}

/**
 * div - Divides the top 2 element in a stack
 *
 * @stack: Stack
 * @line_number: Instruction Line number
 */
void divop(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;

	(*stack)->next->n = quotient;

	pop(stack, line_number);
}
