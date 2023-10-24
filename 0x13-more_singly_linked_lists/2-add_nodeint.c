#include "lists.h"

/**
 * add_nodeint - inserts a node at the beginning of the list
 * @head: a pointer to the head node
 * @value: the integer value to store
 *
 * Return: a pointer to the new head, else NULL on failure.
 */
listint_t *add_nodeint(listint_t **head, const int value)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL); /* memory allocation for new node failed */

	new_node->n = value;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
