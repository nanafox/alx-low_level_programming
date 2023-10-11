/**
 * print_name - prints a name
 * @name: the name to print
 * @fptr: a function pointer
 */
void print_name(char *name, void (*fptr)(char *))
{
	if (!name || *name == '\0' || !fptr)
		/* either the name or the function pointer is NULL */
		return;

	/* call the function pointer for further processing */
	fptr(name);
}
