#include "lists.h"

listint_t *get_loop_start(listint_t *slow_ptr, listint_t *head);

/**
 * find_listint_loop - detects a loop in the linked list
 * @head: the head of the linked list
 *
 * Return: a pointer to the node where th loop starts,
 * or NULL if there was no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast_ptr = head;
	listint_t *slow_ptr = head;

	if (head == NULL)
	{
		return (NULL);
	}

	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;

		if (slow_ptr == fast_ptr)
		{
			return (get_loop_start(slow_ptr, head));
		}
	}

	return (NULL); /* no loops were found */
}

/**
 * get_loop_start - returns the starting point of a loop in the linked list
 * @slow_ptr: the slow pointer
 * @head: the head node
 *
 * Return: the address of the node causing the loop
 */
listint_t *get_loop_start(listint_t *slow_ptr, listint_t *head)
{
	if (head == NULL || slow_ptr == NULL)
	{
		return (NULL);
	}

	while (head != slow_ptr)
	{
		head = head->next;
		slow_ptr = slow_ptr->next;
	}

	return (head); /* the start of the loop */
}
