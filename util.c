#include "monty.h"

/**
 * A_sh_toggle - Toggle a boolean value
 *
 * @value: Pointer to a short value
 */
void A_sh_toggle(short *value)
{
	if (*value)
		*value = 0;
	else
		*value = 1;
}

/**
 * A_sh_print - Prints an array of strings
 *
 * @str: Pointer to an array of strings to print
 */
void A_sh_print(char **str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
	}

}

