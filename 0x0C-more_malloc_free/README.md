# Dynamic Memory Allocation

Solutions to project **0x0C-more_malloc_free**

## Function Prototypes

All required function prototypes can be found [here](main.h).

## Tasks

1. [Malloc Checked](0-malloc_checked.c)
 
   Prototype: `void *malloc_checked(unsigned int size);` <br />

   Memory is dynamically allocated using the `malloc()` function. 
   In the event of an error, a normal process termination occurs 
   with status code 98.

2. [Dynamic String Concatenation](1-string_nconcat.c)

   Prototype: `char *string_nconcact(char *s1, char *s2, unsigned int n);` <br />
 
   This is a variant of the `strncat()` function. The difference is that this
   function dynamically allocated memory for the new string and the content of
   strings `s1` and `s2` are concatenated to it, basically a copy process. It
   handles memory allocation failures and other edge cases to ensure the string
   returned is valid.

3. [_calloc - Allocating and setting memory to zero](2-calloc.c)

   Prototype: `void *_calloc(unsigned int nmemb, unsigned int size);` <br />
 
   The `_calloc()` function allocates memory for an array of `nmemb` (Number of elements)
   of `size` bytes for each. The resultant memory allocated equals `nmemb` * `size`.
   The memory is set with zero using the `_memset()` function before returning a pointer
   to the newly allocated memory. If an error occurs, `NULL` is returned instead.

4. [_realloc - Reallocating Dynamic Memory Blocks](100-realloc.c)

   Prototype: `void *_realloc(void *old_mem_blk, unsigned int old_size, unsigned int new_size);` <br />
 
   This function simply takes care of shrinking or expanding an already allocated memory block.
   It works just like the `realloc()` function that comes with the C standard library. Errors
   handling so the memory address return to the calling function is always valid. In the event
   of an error, `NULL` is returned. There are no undefined behaviors.

5. [Arithmetic on the CLI - Finding the Product](101-mul.c)

   Prototype: `int main(int argc, char *argv[]);` <br />
   Usage: `mul num1 num2` <br />
 
   This is a combination of command line arguments and dynamic memory allocation.
   The function accepts **exactly** two arguments, anything less or more will cause
   a normal process termination with status code 98. On a successful run, the product
   of `num1` and `num2` are written to `stdout`. 
