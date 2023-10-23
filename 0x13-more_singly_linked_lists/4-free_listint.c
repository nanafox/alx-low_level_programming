#include "lists.h"

/**
 * free_listint - frees memory allocated to a linked list of integers
 * @head: the head node
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	if (head == NULL)
		return; /* the list is empty, nothing to free */

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
