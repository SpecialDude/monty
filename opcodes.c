#include "monty.h"

instruction_t all_instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pop", pop},
	{"pint", pint},
	{"swap", swap},
	{"add", add},
	{NULL, NULL}
};

char *useless_instructions[] = {"nop", NULL};

/**
 * is_NII - Not Important Instruction
 *
 * @opcode: instruction
 *
 * Return: int
 */
int is_NII(char *opcode)
{
	int i;

	for (i = 0; useless_instructions[i]; i++)
	{
		if (strcmp(opcode, useless_instructions[i]) == 0)
			return (1);
	}

	return (0);
}

/**
 * get_instruction - Get the instruction object
 *
 * @opcode: opcode
 *
 * Return: Function pointer
 */
void (*get_instruction(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;

	for (; all_instructions[i].opcode; i++)
	{
		if (strcmp(opcode, all_instructions[i].opcode) == 0)
			return (all_instructions[i].f);
	}

	return (NULL);
}

/**
 * execute - Executes opcode
 *
 * @line: Line in bytecodes
 *
 * @line_number: line number
 */
void execute(char *line, int line_number)
{
	char *opcode;

	void (*instruction)(stack_t **, unsigned int);

	instruction_args = parse_line(line);

	if (instruction_args == NULL)
		return;

	opcode = instruction_args[0];

	if (!is_NII(opcode))
	{
		instruction = get_instruction(opcode);

		if (instruction == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		instruction(&stack, line_number);
	}

	instruction_args_count = 0;
	free_memory(instruction_args);
}
