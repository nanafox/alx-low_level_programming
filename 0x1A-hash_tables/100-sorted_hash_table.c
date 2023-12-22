#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: the size of the array of buckets
 *
 * Return: a pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sorted_hash_map;
	unsigned long int i;

	if (!size)
		return (NULL);

	sorted_hash_map = malloc(sizeof(shash_table_t));
	if (sorted_hash_map == NULL)
		return (NULL);

	sorted_hash_map->size = size;

	/* allocate memory for the array of linked lists */
	sorted_hash_map->array = calloc(size, sizeof(shash_node_t));
	if (sorted_hash_map->array == NULL)
	{
		free(sorted_hash_map);
		sorted_hash_map = NULL;
		return (NULL);
	}

	/* initialize the array of linked lists */
	for (i = 0; i < size; i++)
		sorted_hash_map->array[i] = NULL;

	sorted_hash_map->shead = NULL;
	sorted_hash_map->stail = NULL;

	return (sorted_hash_map);
}

/**
 * shash_table_set - adds an element to a sorted hash table
 * @ht: the hash table to insert into
 * @key: the key
 * @value: the value
 *
 * Return: 1 if insertion succeeds, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0); /* insertion failed: invalid parameter */

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			if (strcmp(tmp->value, value) == 0)
				return (1); /* value already exists */

			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->snext;
	}
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0); /* insertion failed: memory allocation failed */

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (0);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		multi_free2("sn", node->key, node);
		return (0);
	}

	handle_sorted_insertion(ht, node, index);
	return (1);
}

/**
 * handle_sorted_insertion - handles the sorted insertion of hash tables
 * @ht: the hash table to sort
 * @node: the current node to insert
 * @idx: the index of the key (where to insert at)
 */
void handle_sorted_insertion(shash_table_t *ht, shash_node_t *node, size_t idx)
{
	shash_node_t *tmp;

	/* handle insertion */
	node->next = ht->array[idx];
	ht->array[idx] = node;

	/* handle insertion when the sorted bucket is empty */
	if (ht->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
	}
	else if (strcmp(ht->shead->key, node->key) > 0)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else /* handle insertion within the bucket */
	{
		tmp = ht->shead;

		/* find the location to insert this new key */
		while (tmp->snext != NULL && strcmp(tmp->snext->key, node->key) < 0)
			tmp = tmp->snext;

		node->sprev = tmp;
		node->snext = tmp->snext;

		if (tmp->snext == NULL)
			ht->stail = node;
		else
			tmp->snext->sprev = node;

		tmp->snext = node;
	}
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table to retrieve the data from
 * @key: the key
 *
 * Return: the value associated with the key if found, else NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size || ht->array[index] == NULL)
		return (NULL);

	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
	{
		tmp = tmp->snext;
	}

	return ((tmp == NULL) ? NULL : tmp->value); /* return the value if found*/
}

/**
 * shash_table_print - prints a hash table in sorted order
 * @ht: the table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return; /* the hash table is not initialized */

	putchar('{');

	node = ht->shead;
	while (node != NULL)
	{
		/* for chained conditions, format with the commas as well */
		printf("'%s': '%s'%s", node->key, node->value,
			   (node->snext) ? ", " : "");

		node = node->snext;
	}
	puts("}");
}

/**
 * shash_table_print_rev - prints a hash table in reversed sorted order
 * @ht: the table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return; /* the hash table is not initialized */

	putchar('{');
	node = ht->stail;

	while (node != NULL)
	{
		/* for chained conditions, format with the commas as well */
		printf("'%s': '%s'%s", node->key, node->value,
			   (node->sprev) ? ", " : "");

		node = node->sprev;
	}
	puts("}");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return; /* nothing to free: the hash table is not initialized  */

	if (ht->shead)
	{
		shash_node_t *tmp;

		while (ht->shead != NULL)
		{
			tmp = ht->shead;
			ht->shead = ht->shead->snext;

			free(tmp->value);
			free(tmp->key);
			free(tmp);
		}
		free(ht->array);
	}

	free(ht);
}

/**
 * multi_free2 - frees multiple data objects
 * @format: the format of objects to free
 */
void multi_free2(const char *format, ...)
{
	char *str;
	shash_node_t *node;

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
			node = va_arg(items, shash_node_t *);
			free(node);
			node = NULL;
			break;
		}
		format++;
	}
}
