#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @head: the head node
 *
 * Return: the number of elements in the linked list
 */
size_t list_len(const list_t *head)
{
	size_t node_count = 0;
	list_t *tmp_head = (list_t *) head;

	if (tmp_head == NULL)
	{
		return (0); /* list is empty */
	}

	/* get the number of element in the linked list */
	while (tmp_head != NULL)
	{
		node_count++;
		tmp_head = tmp_head->next;
	}

	return (node_count);
}

