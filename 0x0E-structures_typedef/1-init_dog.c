#include "dog.h"
#include <stdlib.h>

char *_strdup(const char *str);
unsigned int _strlen(const char *str);

/**
 * init_dog - Initializer for dog structure
 * @new_dog: Pointer to dog structure
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the dog's owner
 */
void init_dog(struct dog *new_dog, char *name, float age, char *owner)
{
	if (new_dog == NULL)
		new_dog = malloc(sizeof(dog_t)); /* allocate memory for initialization */

	if (new_dog == NULL)
		return; /* initialization failed, dog can't be created */

	/* add dog details */
	new_dog->name = _strdup(name);

	/* handle memory allocation failure */
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return;
	}

	new_dog->owner = _strdup(owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return;
	}

	new_dog->age = age;
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
 * _strlen - get the length of a string
 * @str: String
 *
 * Return: The length of string @s
 */
unsigned int _strlen(const char *str)
{
	unsigned int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}
