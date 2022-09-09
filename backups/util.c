#include "monty.h"

typedef struct file_s
{
    char *filename;
    size_t filesize;
} file_t;

/**
 * get_my_malloc_size - Get the allocated size of a pointer
 *
 * @ptr: pointer
 *
 * Return: size_t
 */
size_t get_my_malloc_size(void *ptr)
{
	size_t *cp = ptr;

	if (cp)
	{
		--cp;
		if (cp)
			return (*cp);
	}

	return (-1);
}

/**
 * _realloc_or_exit - Reallocate memory (and keep size)
 * exits on allocation error
 *
 * @ptr: pointer
 * @new_size: size
 *
 * Return: void* (Pointer to new memory block)
 */
void *_realloc_or_exit(void *ptr, size_t new_size)
{
	void *newptr;
	size_t size, min_size;


	if (ptr == NULL)
		return _malloc_or_exit(new_size);

	size = get_my_malloc_size(ptr);
	min_size = (size < new_size) ? size : new_size;

	newptr = _malloc_or_exit(new_size);

	newptr = memcpy(newptr, ptr, min_size);

	mfree(ptr);

	return (newptr);
}

/**
 * _malloc_or_exit - Allocate memory (and keep size)
 * exits on allocation error
 *
 * @size: size
 *
 * Return: void* (Pointer to new memory block)
 */
void *_malloc_or_exit(size_t size)
{
	size_t *newmem;
	char *msg;

	newmem = malloc(size + sizeof(size_t));

	if (newmem == NULL)
	{
		msg = "Error: malloc failed\n";
		write(STDERR_FILENO, msg, 21);
		/* fprintf(stderr, "%s", msg); */
		exit(EXIT_FAILURE);
	}

	*newmem = size;
	newmem++;
	return (newmem);
}

/**
 * mfree - Free Memory allocated with size keep
 *
 * @ptr: pointer
 *
 * Return: void
 */
void mfree(void *ptr)
{
	size_t *cp;

	if (ptr != NULL)
	{
		cp = ptr;

		if (--cp)
			free(cp);
	}
}

file_t *open_file(char *filename)
{
    file_t *file = _malloc_or_exit(sizeof(file_t));
    FILE *fd;

    file->filename = filename;

    fd = fopen(filename, "r");


    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fd, 0L, SEEK_END);

    file->filesize = ftell(fd);

    fclose(fd);

    return (file);
}

char *read_file(file_t *file)
{
    char *filecontent;
    int fd;
    ssize_t size;

    fd = open(file->filename, O_RDONLY);

    filecontent = _malloc_or_exit(sizeof(char) * file->filesize);

    size = read(fd, filecontent, file->filesize);

    if (size < 0)
    {
        fprintf(stderr, "Error: Can't read file %s\n", file->filename);
        mfree(filecontent);
        exit(EXIT_FAILURE);
    }
    else if (size == 0)
    {
        fprintf(stderr, "EOF REACHED\n");
    }

    close(fd);


    return filecontent;
}

