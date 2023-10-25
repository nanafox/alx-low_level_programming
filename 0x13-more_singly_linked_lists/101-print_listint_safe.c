#include "lists.h"

/**
 * print_listint_safe - prints a linked list and checks for a loop
 * @head: a pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count, i;
	/* an array of listint_t nodes */
	const listint_t **visited_nodes = NULL;

	if (head == NULL)
	{
		return (0); /* the list is already empty */
	}

	node_count = 0;
	while (head != NULL)
	{
		for (i = 0; i < node_count; i++)
		{
			/*
			 * check if the current node has been visited already
			 * it could be a possible loop candidate
			 */
			if (head == visited_nodes[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(visited_nodes);
				return (node_count);
			}
		}

		node_count++;

		/* keeps track of the nodes visited so far */
		visited_nodes = append_to_list(visited_nodes, node_count, head);

		/* print current node's information */
		printf("[%p] %d\n", (void *)head, head->n);

		head = head->next;
	}

	free(visited_nodes);
	return (node_count);
}

/**
 * append_to_list - keeps track of all nodes visited in a linked list
 * @node_list: the old list to append to (contains the list of visited nodes)
 * @node_count: the number of nodes to append to the list
 * @new_node: the new node to append to the list
 *
 * Return: a pointer the new list of visited nodes
 */
const listint_t **append_to_list(const listint_t **node_list,
		size_t node_count, const listint_t *new_node)
{
	size_t i;
	const listint_t **visited_nodes;

	visited_nodes = malloc(node_count * sizeof(listint_t *));
	if (visited_nodes == NULL)
	{
		exit(98); /* memory allocation failed */
	}

	/* append the nodes to the list */
	for (i = 0; i < node_count - 1; i++)
	{
		visited_nodes[i] = node_list[i];
	}
	visited_nodes[i] = new_node; /* append the new node to the list */

	free(node_list); /* free the previous memory */
	return (visited_nodes);
}
