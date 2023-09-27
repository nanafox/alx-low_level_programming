#include <string.h>

int palindrome_helper(char *s, int start, int end);

/**
 * is_palindrome - checks if a string is palindrome or not
 * @s: string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	return (palindrome_helper(s, 0, strlen(s) - 1));
}

/**
 * palindrome_helper - A helper function to check if a string is palindrome
 * @s: string
 * @start: character at the start index position
 * @end: character at the end index position
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int palindrome_helper(char *s, int start, int end)
{
	if (*s == '\0') /* handle empty strings */
		return (0);

	if (s[start] != s[end])
		return (0);
	if (start >= end)
		return (1);

	return (palindrome_helper(s, start + 1, end - 1));
}
