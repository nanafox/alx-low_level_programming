#include "lists.h"

/**
 * free_listint2 - frees memory allocated to a linked list of integers
 * while avoiding dangling pointers
 * @head: a pointer to the head node
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return; /* the list is already empty, there's nothing to be free'd */

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		safe_free(tmp);
	}
}

/**
 * _free - a safer way to free dynamically allocated memory
 * @ptr: pointer to memory location
 *
 * Description: This _free() function takes care of freeing
 * dynamically allocated memory while ensuring the pointer
 * @ptr passed to it is not NULL before trying to free it.
 * Also, after freeing the memory, it sets the pointer @ptr
 * to NULL to avoid the issue of dangling pointers.
 */
void _free(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
