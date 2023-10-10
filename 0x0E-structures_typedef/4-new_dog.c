#include "dog.h"
#include <stdlib.h>

char *_strdup(const char *str);
unsigned int _strlen(const char *s);

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the dog's owner
 *
 * Return: A pointer to the newly created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	/* allocate memory for the new instance of the dog entity */
	dog_t *dog = malloc(sizeof(dog_t));

	/* add dog details and also handle memory allocation failures */
	dog->name = _strdup(name);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL); /* memory allocation failed - clean up and leave */
	}

	dog->owner = _strdup(owner);
	if (dog->owner == NULL)
	{
		free(dog->name);
		return (NULL); /* memory allocation failed while duplicating owner's name */
	}

	dog->age = age; /* save the age of the dog */

	return (dog);
}

/**
 * _strdup - Duplicates a string.
 * @str: String to duplicate
 *
 * Description: The _strdup() function returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string @str. Memory for the
 * new string is obtained with malloc() and can be freed with free()
 *
 * Return: A pointer to the duplicated string, NULL if it fails
 */
char *_strdup(const char *str)
{
	char *dup_str;
	int i = 0;

	if (str == NULL)
		return (NULL); /* handle invalid string */

	dup_str = (char *) malloc(sizeof(char) * (_strlen(str) + 1));

	if (dup_str == NULL)
		return (NULL);

	/* duplicate string - a copy process */
	while (str[i] != '\0')
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';

	return (dup_str);
}

/**
 * _strlen - Get the length of a string
 * @s: String
 *
 * Return: The length of string @s
 */
unsigned int _strlen(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}
