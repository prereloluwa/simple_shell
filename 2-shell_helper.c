#include "shell.h"

/**
 *print - print value passed
 *@var: value passed
 *@fd: file
 *
 *Return: value
 */
int print(char *var, int fd)
{
	return (write(fd, var, strlen(var)));
}

/**
 *get_func - check for different function
 *@command: command passed character argument
 *
 *Return: void
 */
void (*get_func(char *command))(char **)
{
	int i;

	map_func map[] = {
		{"env", env},
		{"cd", ch_dir},
		{"exit", quit}
	};

	for (i = 0; i < 3; i++)
	{
		if (_strcmp(command, map[i].cmd_name) == 0)
			return (map[i].func);
	}
	return (NULL);
}
