#include "monty.h"

int main(int ac, char **av)
{
    char *filename;
    int i = 0;


    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    filename = *(av + 1);

    printf("Filename: %s\n", filename);

    filename =  read_file(open_file(filename));

    while (filename[i])
    {
        printf("char: %c\tint: %d\n", filename[i], (int)filename[i]);
        i++;
    }

    printf("char: %c\tint: %d\n", filename[i], (int)filename[i]);
    printf("Allocated size: %ld\n", get_my_malloc_size(filename));
    printf("Str len: %ld\n", strlen(filename));

    return (EXIT_SUCCESS);
}