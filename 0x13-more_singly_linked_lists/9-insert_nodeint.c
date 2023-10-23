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
	listint_t *new_node, *prev, *cur;

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

	while (cur != NULL)
	{

		/* insert at an intermediate position if the index is found */
		if (i == idx)
		{
			prev->next = new_node;
			new_node->next = cur;
			return (*head);
		}
		else
		{
			prev = cur; /* keep track of the previous node */
			cur = cur->next;
			i++;
		}
	}

	/* handle insertion at the tail */
	if (idx == i)
	{
		prev->next = new_node;
		return (*head);
	}

	free(new_node); /* insertion failed */
	new_node = NULL;

	return (NULL); /* new node insertion failed */
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
