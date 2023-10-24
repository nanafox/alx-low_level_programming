#include "lists.h"

/**
 * free_listint_safe - safely deallocates memory for a linked list and checks
 * for a loop
 * @head: a pointer to the start of the list
 *
 * Return: the number of nodes in the free'd list
 */
size_t free_listint_safe(listint_t **head)
{
	listint_t *tmp;
	ssize_t offset;
	size_t node_count = 0;

	if (head == NULL || *head == NULL)
	{
		return (0); /* the list is empty, there's nothing to free */
	}

	while (*head != NULL)
	{
		offset = *head - (*head)->next;

		/* free the nodes before the loop is encountered, if any */
		if (offset > 0)
		{
			tmp = (*head);
			(*head) = (*head)->next;
			free(tmp);
			tmp = NULL;
			node_count++;
		}
		else
		{
			/* a loop was found, clean up and leave */
			free(*head);
			*head = NULL;
			node_count++;
			break;
		}
	}

	*head = NULL; /* avoid danlging pointer */
	return (node_count);
}
