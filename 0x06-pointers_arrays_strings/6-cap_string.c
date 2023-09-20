/* set of possible string delimeters */
#define TAB '\t'
#define BLANK ' '
#define NEWLINE '\n'
#define DOT '.'
#define COMMA ','
#define SEMI_COLON ';'
#define QUOTE '"'
#define ISDELIM(c) ( \
	c == TAB || c == BLANK || c == NEWLINE || c == COMMA  || \
	c == DOT || c == SEMI_COLON || c == '?' || c == QUOTE ||  \
	c == '(' || c == ')' || c == '{' || c == '}' || c == '!' \
)
#define INTERVAL 32
#define to_upper(c) ((c >= 'a' && c <= 'z') ? c - INTERVAL : c)
#define to_lower(c) ((c >= 'A' && c <= 'Z') ? c + INTERVAL : c)

/**
 * cap_string - capitalize the first letter of each word in a string
 * @s: string
 *
 * Return: a pointer to the string
 */
char *cap_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0) /* capitalize the first letter in the s */
			s[i] = to_upper(s[i]);
		else if (s[i] == TAB)
			s[i] = ' '; /* convert tab to a single space */
		else if (ISDELIM(s[i - 1])) /* change to upper case after each delimeter */
			s[i] = to_upper(s[i]);
	}
	return (s);
}
