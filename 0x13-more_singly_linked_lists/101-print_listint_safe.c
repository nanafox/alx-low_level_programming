#include "lists.h"

listint_t *get_loop_start(listint_t *slow_ptr, listint_t *head);
listint_t *detect_loop(const listint_t *head);

/**
 * print_listint_safe - prints all the nodes in a listint_t list
 * while accounting for possible loops
 * @head: the head
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	int loop_detected = 0;
	listint_t *slow_ptr = NULL;
	const listint_t *loop_start = NULL;
	const listint_t *loop_start_copy = NULL;

	if (head == NULL)
		exit(98);

	while (head != NULL)
	{
		slow_ptr = detect_loop((listint_t *)head);
		if (slow_ptr)
		{
			loop_detected = 1;
			loop_start = get_loop_start(slow_ptr, (listint_t *)head);
			loop_start_copy = loop_start;
			while (head != loop_start)
			{
				printf("[%p] %d\n", (void *)head, head->n);
				head = head->next;
				node_count++;
			}

			/* print the nodes after the loop */
			while (loop_start_copy->next != head)
			{
				printf("[%p] %d\n", (void *)loop_start_copy, loop_start_copy->n);
				loop_start_copy = loop_start_copy->next;
				node_count++;
			}
			/* print the last node */
			printf("[%p] %d\n", (void *)loop_start_copy, loop_start_copy->n);
			node_count++;
			break;
		}

		/* the list does not contain a loop - print as normal */
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		node_count++;
	}

	/* if a loop was detected, print the start node of the loop */
	if (loop_detected)
	{
		printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
	}

	return (node_count);
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
	listint_t *tmp = head;

	while (tmp != slow_ptr)
	{
		tmp = tmp->next;
		slow_ptr = slow_ptr->next;
	}
	return (tmp);
}

/**
 * detect_loop - detects a loop in the linked list
 * @head: the head of the linked list
 *
 * Return: If a loop is detected, return a pointer to the node where the
 * loop starts; otherwise, return NULL.
 */
listint_t *detect_loop(const listint_t *head)
{
	listint_t *fast_ptr = (listint_t *)head;
	listint_t *slow_ptr = (listint_t *)head;

	while (fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;

		if (fast_ptr == slow_ptr)
		{
			return (slow_ptr);
		}
	}
	return (NULL);
}
