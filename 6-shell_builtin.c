#include "shell.h"

/**
 *env - print character in environment
 *@command: argument
 *
 *Return: void
 */
void env(char **command __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		print(environ[i++], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 *quit - exit environment
 *@command: argumment
 *
 *Return: void
 */
void quit(char **command)
{
	(void) command;
}

/**
 *ch_dir - change directory
 *@command: argumment
 *
 *Return: void
 */
void ch_dir(char **command)
{
	(void) command;
}
