#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table to retrieve the data from
 * @key: the key
 *
 * Return: the value associated with the key if found, else NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	if (ht->array[index] == NULL)
		return (NULL); /* the key was not found */

	/* handle collisions */
	if (strcmp(key, ht->array[index]->key) != 0)
	{
		hash_node_t *tmp = ht->array[index];

		while (tmp != NULL)
		{
			if (strcmp(key, tmp->key) == 0)
				return (tmp->value);

			tmp = tmp->next;
		}
	}
	else
		return (ht->array[index]->value); /* there were no collision */

	return (NULL); /* the key was not found */
}
