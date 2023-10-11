#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform the operation asked
 * by the user.
 * @operator: the operator specified by the user
 *
 * Return: a pointer to the function that corresponds to the operator given
 * as a parameter
 */
int (*get_op_func(char *operator))(int, int)
{
	int i;

	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	i = 0;
	while (ops[i].op != NULL)
	{
		if (!strcmp(ops[i].op, operator))
			return (ops[i].operation); /* return the right opertor for operation */
		i++;
	}

	return (NULL); /* invalid operator received */
}
