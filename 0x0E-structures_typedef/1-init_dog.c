#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializer for dog structure
 * @d: pointer to dog structure
 * @name: name of dog
 * @age: age of dog
 * @owner: name of dog owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog)); /* assign enough space to hold data */
	d->age = age;
	d->name = name;
	d->owner = owner;
}
