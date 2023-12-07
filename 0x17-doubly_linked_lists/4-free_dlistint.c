#include "lists.h"

/**
 * free_dlistint - cleans up memory allocated for a dlistint_t list
 * @head: the head node
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head == NULL)
		return; /* there's nothing to free */

	while (head != NULL)
	{
		/* clean up space for the current node */
		tmp = head;
		free(tmp);
		tmp = NULL;

		/* move to the next node and free that too */
		head = head->next;
	}
}
