#include "lists.h"

/**
 * reverse_listint - reverses a listint_t list
 * @head: a pointer to the head node
 *
 * Return: a pointer to the (reversed) head node, else NULL on error
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next_node, *prev_node;

	if (*head == NULL)
		return (NULL);

	prev_node = NULL;
	while (*head != NULL)
	{
		/* adjust links, reversing the linked list */
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}
	*head = prev_node;

	return (*head);
}
