#include "main.h"
#include <string.h>
#define check_null(s) ((s == 0) ? (s = "") : s) /* handle null strings */

/**
 * str_concat - Concatenates two strings.
 * @s1: String 1
 * @s2: String 2
 *
 * Return: A pointer to a newly allocated space in memory which
 * contains the contents of @s1 and @s2, NULL if it fails.
 */
char *str_concat(char *s1, char *s2)
{
	char *new_string;
	unsigned int i, j, len;

	check_null(s1);
	check_null(s2);

	len = strlen(s1) + strlen(s2); /* get the length of both strings */

	new_string = (char *) malloc(len + 1);

	if (new_string == NULL)
		return (NULL);

	/* copy the contents of the first string - s1*/
	i = 0;
	while (*(s1 + i))
	{
		*(new_string + i) = *(s1 + i);
		i++;
	}

	j = i; /* save the current position in the new_string */

	/* copy the contents of the second string - s2 */
	i = 0;
	while (*(s2 + i))
	{
		*(new_string + j) = *(s2 + i);
		i++;
		j++;
	}
	*(new_string + j) = '\0';

	return (new_string);
}
