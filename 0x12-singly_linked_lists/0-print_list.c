#include "lists.h"

/**
 * print_list - prints all the element of a list_t list
 * @head: the head node
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *head)
{
	size_t node_count = 0;

	/* handle cases where the list is empty */
	if (head == NULL)
	{
		return (0);
	}

	while (head != NULL)
	{
		/* handle NULL strings */
		if (head->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", head->len, head->str);
		node_count++;
		head = head->next;
	}

	return (node_count);
}
