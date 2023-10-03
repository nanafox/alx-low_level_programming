#include <stdlib.h>
#include <string.h>

#define isspace(c) ((c == ' ') ? 1 : 0)

/* helper functions */
int get_word_count(const char *str);
void free_str(char **str_array, int num_of_words);
char *new_word(const char *str, int start, int end);

/**
 * strtow - splits a string into words.
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words) on success, NULL otherwise.
 */
char **strtow(char *str)
{
	char **str_array;
	int word_count, word_start, word_end; /* keeps track of words */
	int len, index, i;

	word_count = get_word_count(str);
	if (!word_count)
		return (NULL); /* no valid words */

	str_array = malloc((word_count + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);

	word_start = index = 0;
	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (!isspace(str[i]) && (isspace(str[i + 1]) || str[i + 1] == '\0'))
		{
			/* get the length of the newly word found, allocate memory and copy it */
			word_end = i + 1;
			str_array[index] = new_word(str, word_start, word_end);

			/* memory allocation for new word failed, clean up and leave */
			if (str_array[index] == NULL)
				return (free_str(str_array, index), NULL);
			index++;
		}
		else if (!isspace(str[i]) && !isspace(str[i + 1]))
			continue;
		else
			word_start = i + 1;
	}
	/* terminate the array */
	str_array[index] = NULL;

	return (str_array);
}

/**
 * new_word - gets a word a from string and writes it to a memory buffer
 * @str: string to copy from
 * @start: start index of the new word in the string
 * @end: end index of word
 *
 * Return: A pointer to the new word
 */
char *new_word(const char *str, int start, int end)
{
	char *new_word;
	int word_len = end - start;

	new_word = malloc(sizeof(char) * (word_len + 1));
	if (new_word == NULL)
		return (NULL);

	strncpy(new_word, str + start, word_len);
	new_word[word_len] = '\0';

	return (new_word);
}

/**
 * get_word_count - Returns the number of words in a string.
 * @str: String
 *
 * Return: Number of words
 */
int get_word_count(const char *str)
{
	int in_word = 0; /* flag to track if we are in a word or not */
	int word_count = 0;

	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (isspace(*str))
			in_word = 0; /* not in a word, reset flag */
		else if (!in_word)
		{
			in_word = 1; /* found the start of a new word */
			word_count++; /* count word */
		}
		str++;
	}

	return (word_count);
}

/**
 * free_str - frees memory allocated for an array of strings
 * @str_array: string array
 * @num_of_words: number of words
 */
void free_str(char **str_array, int num_of_words)
{
	int i = 0;

	for (i = 0; i < num_of_words; i++)
		free(str_array[i]);
	free(str_array);
}
