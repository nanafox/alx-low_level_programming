#include "lists.h"

/**
 * print_listint_safe - prints a linked list and checks for a loop
 * @head: a pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	ssize_t offset;

	if (head == NULL)
	{
		return (0);
	}

	while (head)
	{
		offset = head - head->next; /* get the difference */
		node_count++;

		/* no loops found yet, print the address and data of the current node */
		printf("[%p] %d\n", (void *)head, head->n);

		/* ensure the current node's address is ahead of the next in memory */
		if (offset > 0)
		{
			head = head->next;
		}
		else
		{
			/* a loop was found - print where it begins */
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}
	}

	return (node_count);
}
