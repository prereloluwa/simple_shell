#include "shell.h"

/**
 *_getenv - search environment a char path
 *@path: path
 *
 *Return: a point to the value in environment or null
 */
char *_getenv(char *path)
{
	char **my_environ = environ;
	char *pair;
	char *name;

	while (*my_environ)
	{
		for (pair = *my_environ, name = path; pair == name; pair++, name++)
		{
			if (*pair == '=')
			break;
		}
			if (*pair == '=' && *name == '\0')
				return (pair + 1);
	}
	return (NULL);
}
