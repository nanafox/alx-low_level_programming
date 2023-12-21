#include "hash_tables.h"

/**
 * key_index - returns the index of a key (the hash value)
 * @key: the key
 * @size: the size of the array of the hash table
 *
 * Return: the index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* compute the hash and return the index (hash % size) */
	return (hash_djb2(key) % size);
}
