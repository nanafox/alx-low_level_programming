#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: the head node (starting point of the list)
 * @index: the index of the nth node to return
 *
 * Return: the address of the nth node if found, else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t c_index = 0;

	if (head == NULL)
		return (NULL); /* the list is empty */

	/* is it the first element? */
	if (index == 0)
		return (head);

	/* let's search for it within the list */
	while (head != NULL && c_index < index)
	{
		head = head->next;
		c_index++;
	}

	/* return the node found, it could be NULL at this point */
	return (head);
}
