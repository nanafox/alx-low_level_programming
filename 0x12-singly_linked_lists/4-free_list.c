#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: the head node
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next; /* move to the next node */
		safe_free(current_node->str); /* free memory allocated for the string */
		safe_free(current_node); /* free memory for the current node */
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
 * to NULL to avoid the issue of dangling pointers
 */
void _free(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
