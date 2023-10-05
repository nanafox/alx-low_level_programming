#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>

int _putchar(int c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *old_mem_blk, unsigned int old_size, unsigned int new_size);

#endif
