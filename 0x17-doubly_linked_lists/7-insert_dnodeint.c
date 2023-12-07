#include "lists.h"

/**
 * insert_dnodeint_at_index -  inserts a new node at a given position
 * @h: a pointer to the head node
 * @idx: the index position to insert at (zero indexed)
 * @n: the integer value to insert
 *
 * Return: the address of the new node on success, NULL otherwise
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new_node;
	size_t c_idx;

	/* handle insertion at the beginning */
	if (*h == NULL || idx == 0)
		return (add_dnodeint(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	c_idx = 0;
	current = *h;
	while (current->next != NULL && c_idx < (idx - 1))
	{
		current = current->next;
		c_idx++;
	}

	/* let's check whether the index is valid */
	if ((++c_idx) < idx)
	{
		free(new_node);
		new_node = NULL;
		return (NULL); /* the index is invalid */
	}

	/* adjust links to insert node */
	new_node->next = current->next;
	new_node->prev = current;
	current->next = new_node;

	if (new_node->next != NULL)
	{
		new_node->next->prev = new_node;
	}

	return (new_node);
}
