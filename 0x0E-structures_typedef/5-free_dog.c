#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - free memory space allocated for instance of a dog entity
 * @_dog: pointer to an instance of the dog structure
 */
void free_dog(dog_t *_dog)
{
	if (_dog == NULL)
		return;

	/* free memory space allocated for name and owner members */
	if (_dog->name != NULL)
		free(_dog->name);
	if (_dog->owner != NULL)
		free(_dog->owner);
	free(_dog);
}
