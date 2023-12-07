#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a dlistint_t
 * linked list
 * @head: a pointer to the head node
 * @index: the index of the node to the delete
 *
 * Return: 1 on success, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	size_t c_index;
	dlistint_t *tmp;

	if (*head == NULL || head == NULL)
		return (-1); /* the list is already empty */

	tmp = *head;

	/* handle deletion at the beginning of the list */
	if (index == 0)
	{
		(*head) = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else /* let's search for the node and delete it */
	{
		c_index = 0;

		while (tmp != NULL && c_index != index)
		{
			tmp = tmp->next;
			c_index++;
		}

		if (c_index < index)
			return (-1); /* the index is out of range */

		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next; /* adjust links to delete node */

		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev; /* adjust links to delete node */
	}

	free(tmp);
	tmp = NULL;

	return (1); /* node removed successfully */
}
