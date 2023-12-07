#include "lists.h"

/**
 * print_dlistint - prints all elements of a dlistint_t list
 * @head: the head node (starting point of the lis)
 *
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *head)
{
	size_t num_of_nodes = 0;

	if (head == NULL)
		return (num_of_nodes); /* the list is empty */

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		num_of_nodes++;
	}

	return (num_of_nodes);
}
