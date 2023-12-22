#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to insert into
 * @key: the key
 * @value: the value
 *
 * Return: 1 if insertion succeeds, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index, exit_code = 1;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0); /* insertion failed: invalid parameter */

	node = calloc(1, sizeof(hash_node_t));
	if (node == NULL)
		return (0); /* insertion failed: memory allocation failed */

	index = key_index((const unsigned char *)key, ht->size);
	node->key = strdup(key);
	node->value = strdup(value);

	if (node->key == NULL || node->value == NULL)
	{
		multi_free("ssn", node->key, node->value, node);
		return (0);
	}

	if (ht->array[index] == NULL)
		ht->array[index] = node;
	else
	{
		if (strcmp(ht->array[index]->key, node->key) == 0)
		{
			if (strcmp(ht->array[index]->value, node->value) == 0)
			{
				multi_free("ssn", node->key, node->value, node);
				return (1); /* value already exists */
			}
			free(ht->array[index]->value);
			ht->array[index]->value = strdup(node->value);
			multi_free("ssn", node->key, node->value, node);
			return (1);
		}
		exit_code = handle_collision(ht, node, index); /* handle collision */
	}

	return (exit_code);
}

/**
 * handle_collision - handles collision while inserting into the hash table
 * @ht: the hash table to solve collision for
 * @n: the node causing the collision
 * @idx: the index where the collision is occurring
 *
 * Return: 1 if insertion was successful, 0 otherwise
 */
int handle_collision(hash_table_t *ht, hash_node_t *n, unsigned long int idx)
{
	hash_node_t *tmp;

	if (ht == NULL || n == NULL)
		return (0);

	tmp = ht->array[idx];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, n->key) == 0)
		{
			if (strcmp(tmp->value, n->value) == 0)
			{
				multi_free("ss", n->key, n->value);
				return (1);
			}
			free(tmp->value);
			tmp->value = strdup(n->value);
			multi_free("ssn", n->key, n->value, n);

			return (1);
		}
		tmp = tmp->next;
	}

	/* a collision occurred and the key is new */
	n->next = ht->array[idx];
	ht->array[idx] = n;

	return (1);
}

/**
 * multi_free - frees multiple data objects
 * @format: the format of objects to free
 */
void multi_free(const char *format, ...)
{
	char *str;
	hash_node_t *node;

	va_list(items);
	va_start(items, format);

	while (format && *format)
	{
		switch (*format)
		{
		case 's':
			str = va_arg(items, char *);
			free(str);
			str = NULL;
			break;
		case 'n':
			node = va_arg(items, hash_node_t *);
			free(node);
			node = NULL;
			break;
		}
		format++;
	}
}
