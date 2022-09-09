#include "monty.h"


/**
 * escape_quote - Check if to escape Quote characters
 *
 * @c: Character
 * @insidequote: double quote status
 * @insideSquote: single quote statusror
 *
 * Return: int
 */
int escape_quote(char c, short *insidequote, short *insideSquote)
{
	if (c == '"')
	{
		if (!(*insideSquote))
		{
			A_sh_toggle(insidequote);
			return (1);
		}
	}

	else if (c == '\'')
	{
		if (!(*insidequote))
		{
			A_sh_toggle(insideSquote);
			return (1);
		}
	}

	return (0);
}

/**
 * iswhitespace - Check if a character is whitespace
 *
 * @c: Character
 *
 * Return: int
 */
int iswhitespace(char c)
{
	int i;
	char *spacechars = " \t";

	for (i = 0; spacechars[i]; i++)
	{
		if (c == spacechars[i])
			return (1);
	}

	return (0);
}

/**
 * cleanup - A completely useless function
 * forced to be written inorder to pass stupid betty style
 *
 * @arg: Arg
 * @k: k
 * @args: Args
 * @j: J
 *
 * Return: args
 */
char **cleanup(char *word, int k, char **words, int j, int lastisspace, int i)
{
	if (i == 0 || (i == 1 && lastisspace))
	{
		free(word);
		free(words);
		return NULL;
	}
	if (!lastisspace)
	{
		word[k] = '\0';
		words[j] = word;
		words[j + 1] = NULL;
		instruction_args_count++;
	}
	else
		free(word);
	return (words);
}

/**
 * parse_line - Parse line
 *
 * @line: line
 *
 * Return: char**
 */
char **parse_line(char *line)
{
	int wordbuf_size = WORD_BUF, linewords_size = LINE_WORDS_BUF;
	int i = 0, j = 0, k = 0;
	short lastisspace, insidequote = 0, insideSquote = 0;
	char *word, **words;

	if (!line || !line[0])
		return (NULL);
	lastisspace = iswhitespace(*line) ? 1 : 0;
	words = malloc_or_exit(sizeof(char *) * linewords_size);
	word = malloc_or_exit(sizeof(char) * wordbuf_size);
	while (line[i])
	{
		if (iswhitespace(line[i]) && !insidequote && !insideSquote)
		{
			if (!lastisspace)
			{
				word[k] = '\0';
				words[j++] = word;
				instruction_args_count++;
				wordbuf_size = WORD_BUF;
				k = 0;
				word = malloc_or_exit(sizeof(char) * wordbuf_size);
				lastisspace = 1;
			}
		}
		else if (!escape_quote(line[i], &insidequote, &insideSquote))
		{
			word[k++] = line[i];
			lastisspace = 0;
		}
		i++;
	}

	return (cleanup(word, k, words, j, lastisspace, i));
}
