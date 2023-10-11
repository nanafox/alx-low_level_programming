#ifndef OP_H
#define OP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct cli_arithmetic - blueprint for CLI arithmetic
 *
 * @op: The operator
 * @operation: The function pointer associated to perform operation
 */
typedef struct cli_arithmetic
{
	char *op;
	int (*operation)(int a, int b);
} op_t;


int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif
