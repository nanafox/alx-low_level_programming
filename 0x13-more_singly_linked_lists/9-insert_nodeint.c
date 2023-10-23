#include "lists.h"

listint_t *create_node(void);
listint_t *prepend(listint_t **head, int val);

/**
 * insert_nodeint_at_index - inserts a node at a particular index
 * @head: a pointer to the head node
 * @idx: the index to insert at
 * @val: the integer value to store
 *
 * Return: the head node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int val)
{
	unsigned int i = 0;
	listint_t *new_node, *cur;

	new_node = create_node();
	if (new_node == NULL)
		return (NULL); /* memory allocation for the new node failed */

	/* check if insertion should be at the head (beginning) */
	if (idx == 0)
	{
		return (prepend(head, val));
	}

	new_node->n = val;
	new_node->next = NULL;
	cur = *head;

	while (i < idx - 1)
	{
		/* handle cases where node could not be inserted */
		if (cur == NULL || cur->next == NULL)
		{
			free(new_node); /* free the allocated memory */
			new_node = NULL;
			return (NULL);
		}
		i++;
		cur = cur->next;
	}

	/* insert node */
	new_node->next = cur->next;
	cur->next = new_node;

	return (*head);
}

/**
 * create_node - creates a new listint_t node
 *
 * Return: the new node if successful, else NULL
 */
listint_t *create_node(void)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	return (new_node);
}

/**
 * prepend - inserts a new at the beginning of the list
 * @head: a pointer to the head node
 * @value: the integer value to store
 *
 * Return: the address of the new head, else NULL of failure
 */
listint_t *prepend(listint_t **head, int value)
{
	listint_t *new_node = create_node();

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
