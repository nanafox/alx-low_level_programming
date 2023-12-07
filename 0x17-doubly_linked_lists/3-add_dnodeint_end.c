#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: a pointer to the head node
 * @n: the number to insert
 *
 * Return: the address of the new node on success, else NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL); /* malloc failed */

	new_node->n = n;
	new_node->next = NULL;

	/* handle insertion when the list is empty */
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->prev = NULL;
	}
	/* handle insertion at the end of the list when not empty */
	else
	{
		current = *head;

		while (current->next != NULL)
			current = current->next;

		new_node->prev = current;
		current->next = new_node;
	}

	return (new_node);
}
