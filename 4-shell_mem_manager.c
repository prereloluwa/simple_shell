#include "shell.h"

/**
 *_realloc - reallocate a block of memory
 *@ptr: pointer to previous allocated block
 *@oldsize: byte size of previous block
 *@newsize: byte size of new block
 *
 *Return: pointer
 */

void *_realloc(void *ptr, int oldsize, int newsize)
{
	void *temp;
	int i, min;

	if (!ptr)
		return (malloc(newsize));
	else if (newsize == oldsize)
		return (ptr);
	else if (newsize == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		min = (newsize < oldsize) ? newsize : oldsize;
		temp = malloc(newsize);
		if (temp)
		{
			for (i = 0; i < min; i++)
				*((char *) temp + i) = *((char *) ptr + i);
		free(ptr);
			return (temp);
		}
		else
			return (NULL);
	}
}
