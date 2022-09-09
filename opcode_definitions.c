#include "monty.h"

/**
 * push - Push element to a stack
 *
 * @stack: Stack top
 * @line_number: Line number
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int n;

	new_node = malloc_or_exit(sizeof(stack_t));

	if (instruction_args_count < 2 || !is_integer(instruction_args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(instruction_args[1]);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if ((*stack) != NULL)
	{
		new_node->next = (*stack);
		(*stack)->prev = new_node;
	}
	(*stack) = new_node;

}

/**
 * pall - prints elements of a stack
 *
 * @stack: Stack top
 * @line_number: Line number
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = (*stack);

	while (node)
	{
		printf("%d\n", node->n);

		node = node->next;
	}
	line_number++;

}

/**
 * pop - removes an element from top of stack
 *
 * @stack: Stack top
 * @line_number: Line number
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = (*stack);

	(*stack) = node->next;
	(*stack)->prev = NULL;

	free(node);
}

/**
 * pint - Prints the first element in stack
 *
 * @stack: stack
 *
 * @line_number: line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
