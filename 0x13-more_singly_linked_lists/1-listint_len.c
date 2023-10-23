#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @head: the head node
 *
 * Return: the number of elements in a linked list of integers
 */
size_t listint_len(const listint_t *head)
{
	size_t node_count = 0;

	if (head == NULL)
		return (0); /* the list is empty */

	/* list is not empty, get the number of elements */
	while (head != NULL)
	{
		node_count++;
		head = head->next;
	}

	return (node_count);
}
