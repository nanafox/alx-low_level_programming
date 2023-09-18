#define ISDIGIT(X) ((X >= '0' && X <= '9') ? 1 : 0) /* checks for digits */
#define ISSPACE(X) ((X == ' ') ? 1 : 0) /* checks for spaces */
#define ISALPHA(X) (((X >= 'a' && X <= 'z') || (X >= 'A' && X <= 'Z')) ? 1 : 0)
#define ISNEG(X) ((X == '-') ? -1 : 1)
#define ISSIGN(X) ((X == '-' || X == '+') ? 1 : 0)

/**
 * _atoi - converts a string to an integer
 * @s: string
 *
 * Return: The converted value or 0 on error
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int i, sign;

	sign = 1; /* assume positive sign */

	for (i = 0; !(ISDIGIT(s[i])); i++)
	{
		if (s[i] == '\0') /* empty string or no digits */
			break;
		else if (ISSPACE(s[i]) || ISALPHA(s[i]))
			continue; /* skip characters and whitespaces */
		else if (ISSIGN(s[i]))
			sign *= ISNEG(s[i]); /* update sign */
	}

	for (; ISDIGIT(s[i]); i++)
		num = 10 * num + (s[i] - '0');

	return (num * sign);
}
