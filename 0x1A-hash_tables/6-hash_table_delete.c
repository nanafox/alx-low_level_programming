#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
*/
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return; /* nothing to free: the hash table is not initialized  */

	if (ht->array)
	{
		unsigned long int i;
		hash_node_t *tmp;

		for (i = 0; i < ht->size; i++)
		{
			if (ht->array[i] != NULL)
			{
				while (ht->array[i] != NULL)
				{
					tmp = ht->array[i];
					ht->array[i] = ht->array[i]->next;

					/* free memory for the list - chained nodes inclusive */
					free(tmp->value);
					free(tmp->key);
					free(tmp);
				}
			}
		}
		free(ht->array);
	}

	free(ht);
}
