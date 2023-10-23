#include "lists.h"

/**
 * pop_listint - pops the the head node and returns it's data
 * @head: pointer to the head node
 *
 * Return: the data stored in the popped node
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int data;

	if (*head == NULL)
		return (0); /* list is empty */

	/* adjust links to remove node */
	tmp = *head;
	*head = (*head)->next;

	/* save the data in the node to be popped */
	data = tmp->n;

	/* free memory allocated for the deleted node */
	free(tmp);
	tmp = NULL;

	return (data);
}
