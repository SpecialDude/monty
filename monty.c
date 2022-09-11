#include "monty.h"

stack_t *stack = NULL;
char **instruction_args = NULL;
int instruction_args_count = 0;

/**
 * open_file - Open up a file for reading
 *
 * @filename: file to open
 *
 * Return: FILE*
 */
FILE *open_file(char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * readline - Read content from a file stream
 *
 * @fd: File Stream
 *
 * Return: char*
 */
char *readline(FILE *fd)
{
	char c;
	int i = 0;
	char *line;
	int bufsize = LINE_READ_BUF;
	int size;

	line = malloc_or_exit(sizeof(char) * bufsize);

	while ((c = fgetc(fd)) != EOF)
	{
		if (c == '\n')
		{
			*(line + i) = '\0';
			return (line);
		}

		*(line + i) = c;

		i++;

		if (i > bufsize)
		{
			size = bufsize;
			bufsize += LINE_READ_BUF;
			line = realloc_or_exit(line, size, sizeof(char) * bufsize);
		}
	}

	if (i != 0)
	{
		*(line + i) = '\0';
		return (line);
	}

	free(line);
	return (NULL);
}

/**
 * monty_interpreter - Read and interprete monty bytecodes
 *
 * @filename: name of monty source bytecodes file
 *
 * Return: void
 */
void monty_interpreter(char *filename)
{
	FILE *fd;
	char *line;
	int line_number = 0;

	fd = open_file(filename);

	while ((line = readline(fd)) != NULL)
	{
		line_number++;

		execute(line, line_number);

		free(line);
	}

	fclose(fd);
	free_stack(stack);
}

/**
 * main - Monty Interpreter: Entry point
 *
 * @ac: args count
 * @av: args
 *
 * Return: int
 */
int main(int ac, char **av)
{
	char *filename;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = *(av + 1);

	monty_interpreter(filename);

	return (EXIT_SUCCESS);
}
