#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: a pointer to the head node
 * @str: the string data to add
 *
 * Return: the address of the new node, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *tail;
	char *dup_str;

	tail = *head;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	dup_str = strdup(str);
	if (dup_str == NULL)
	{
		free(new_node); /* clean up memory and return NULL */
		return (NULL);
	}

	new_node->str = dup_str;
	new_node->len = strlen(dup_str);
	new_node->next = NULL;

	/* check if the list is empty - guarantees an O(1) */
	if (*head == NULL)
		*head = new_node;
	else
	{
		/* list is not empty, traverse to the tail. O(n) */
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new_node; /* adjust tail links */
	}

	return (*head);
}
