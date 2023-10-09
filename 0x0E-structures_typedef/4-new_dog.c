#include "dog.h"
#include <stdlib.h>

char *_strcpy(char *dest, const char *src);
unsigned int _strlen(const char *s);

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: a pointer to the newly created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog = malloc(sizeof(dog_t));

	if (dog == NULL)
		return (NULL); /* memory allocation failed */

	dog->name = malloc(sizeof(char) * (_strlen(name) + 1));

	if (dog->name == NULL)
	{
		free(dog);
		return (NULL); /* memory allocation failed - clean up and leave */
	}

	dog->owner = malloc(sizeof(char) * (_strlen(owner) + 1));

	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL); /* memory allocation failed for owner string */
	}

	/* add dog details */
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}

/**
 * _strcpy - copy a string
 * @dest: destination buffer
 * @src: source buffer
 *
 * Description: copies the string pointed to by @src, including the terminating
 * null byte ('\\0'), to the buffer pointed to by @dest. The destination string
 * @dest must be large enough to receive the copy.
 *
 * Return: pointer to @dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - get the length of a string
 * @s: string
 *
 * Return: the length of string @s
 */
unsigned int _strlen(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}
