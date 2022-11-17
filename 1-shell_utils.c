#include "shell.h"

/**
 *ctrl_C - calls control-C
 *@signum: the signal number
 *
 *Return: void
 */
void ctrl_C(int signum)
{
	if (signum == SIGINT)
		print("\n$ ", STDIN_FILENO);
}

/**
 *_getline - get a line
 *
 *Return: 0 on success
 */
char *_getline(void)
{
	int bufsize = READ_BUF, no_read, position = 0;
	char *buffer = malloc(bufsize * sizeof(char));
	char c;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (1)/* continue as long as user is giving input */
	{
		no_read = read(STDIN_FILENO, &c, 1);
		if (c == EOF || !no_read)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				print("\n", STDIN_FILENO);
				return (NULL);
			}
		}
		else if (c == '\n' || !no_read)
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		if (position >= bufsize)
		{
			bufsize += READ_BUF;
			buffer = _realloc(buffer, READ_BUF, bufsize);
		}
		if (!buffer)
		{
			perror("Failed to re-allocate a space in the memory");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * tokenize - split a string
 * @str: the input string
 * @delim: the delimiter string
 * Return: a pointer to an array of strings
 */
char **tokenize(char *str, const char *delim)
{
	int i = 0, j = 0, k = 0, size = 0, lens[1200];
	char **arr;

	if (str == NULL || !(*str))
		return (NULL);
	/* calc no of words and lengths */
	for (i = 0; str[i]; i++)
	{
		if (is_delimeter(delim, str[i])) /* check for delimeter */
			continue;
		/* get the word length */
		j = i;
		while (!is_delimeter(delim, str[i]) && str[i])
			i++;
		if (i > j)
			lens[size++] = i - j;
		if (!str[i])
			break;
	}
	if (!size)
		return (NULL);
	/* create array of strings  */
	arr = malloc((size + 1) * sizeof(char *));
	for (i = 0; str[i]; i++)
	{
		if (is_delimeter(delim, str[i]))
			continue;
		/* copy the word */
		arr[k] = malloc((lens[k] + 1) * sizeof(char));
		j = 0;
		while (!is_delimeter(delim, str[i]) && str[i])
		{
			arr[k][j++] = str[i++];
		}
		arr[k++][j] = '\0';
		if (!str[i])
			break;
	}
	arr[size] = NULL;
	return (arr);
}

/**
 * is_delimeter - check if a character is a delimeter
 * @c: charater to check
 * @delimeters: the delimeter
 * Return: 1 for true 0 for false
 */
int is_delimeter(const char *delimeters, char c)
{
	int i = 0;

	if (!delimeters)
		return (0);
	while (delimeters[i])
	{
		if (delimeters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

