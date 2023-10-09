#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializer for dog structure
 * @new_dog: pointer to dog structure
 * @name: name of dog
 * @age: age of dog
 * @owner: name of dog owner
 */
void init_dog(struct dog *new_dog, char *name, float age, char *owner)
{
	if (new_dog == NULL)
		new_dog = malloc(sizeof(struct dog)); /* assign enough space to hold data */

	if (new_dog == NULL)
		return; /* memory allocation failed */

	/* add dog details */
	new_dog->age = age;
	new_dog->name = name;
	new_dog->owner = owner;
}
