#include "monty.h"

/**
 * malloc_or_exit - Allocate memory
 * exits on allocation error
 *
 * @size: size
 *
 * Return: void* (Pointer to new memory block)
 */
void *malloc_or_exit(size_t size)
{
	void *newmem;
	char *msg;

	newmem = malloc(size);

	if (newmem == NULL)
	{
		msg = "Error: malloc failed\n";
		write(STDERR_FILENO, msg, 21);
		exit(EXIT_FAILURE);
	}

	return (newmem);
}

/**
 * realloc_or_exit - Reallocate memory
 * exits on allocation error
 *
 * @ptr: pointer
 * @size: old size
 * @new_size: new size
 *
 * Return: void* (Pointer to new memory block)
 */
void *realloc_or_exit(void *ptr, size_t size, size_t new_size)
{
	void *newptr;
	size_t min_size;


	if (ptr == NULL)
		return (malloc_or_exit(new_size));

	min_size = (size < new_size) ? size : new_size;

	newptr = malloc_or_exit(new_size);

	newptr = memcpy(newptr, ptr, min_size);

	free(ptr);

	return (newptr);
}

/**
 * free_memory - Free Allocated Memory
 *
 * @ptr: memory pointer
 */
void free_memory(char **ptr)
{
	int i = 0;

	if (!ptr)
		return;

	for (; *(ptr + i); i++)
		free(*(ptr + i));

	free(ptr);
}
