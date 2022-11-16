#include "shell.h"

/**
 * step1: declare a temp memory with initial bufsize
 * step2: copy from buff to tmp
 * step3: free buff
 * step4: reallocate buff with newsize
 * step5: copy from tmp to buff
 * step6: free tmp
 * step7: return the new buff
 */

void *_realloc(void *ptr, int oldsize, int newsize)
{
	void *temp;
	int i, min;

	if (!ptr)
		return (malloc (newsize));
	else if (newsize == oldsize)
		return (ptr);
	else if (newsize == 0 && ptr)
	{
		free (ptr);
		return (NULL);
	}
	else
	{
		min = (newsize < oldsize) ? newsize : oldsize;
		temp = malloc (newsize);
		if (temp)
		{
			for (i = 0; i < min; i++)
				*((char *) temp + i) = *((char *) ptr + i);
			free (ptr);
			return (temp);
		}
		else
			return (NULL);
	}
}
