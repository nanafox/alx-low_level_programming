#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head node
 * @str: the string data
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *dup_str;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL); /* memory allocation for new node failed */
	}

	dup_str = strdup(str);
	if (dup_str == NULL)
	{
		free(new_node);
		return (NULL); /* string duplication failed */
	}

	/* add new node to the list and adjust links */
	new_node->str = dup_str;
	new_node->len = strlen(dup_str);
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
