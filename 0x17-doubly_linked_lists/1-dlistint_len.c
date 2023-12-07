#include "lists.h"

/**
 * dlistint_len - returns the number of nodes in a dlistint_t list
 * @head: the head node
 *
 * Return: the number of nodes in the list
*/
size_t dlistint_len(const dlistint_t *head)
{
	size_t num_of_nodes = 0;

	if (head == NULL)
		return (num_of_nodes); /* the list is already empty so it's zero */

	/* count the number of nodes in the list when it's not empty */
	while (head != NULL)
	{
		num_of_nodes++;
		head = head->next;
	}

	return (num_of_nodes);
}
