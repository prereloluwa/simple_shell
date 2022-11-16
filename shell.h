#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* initial buffer size */
#define READ_BUF 1000

#define DELIM "\a\t\r\n"

/* command types */
#define INTERNAL_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

/* declaring global environ variable */
extern char **environ;

typedef struct internal_function
{
	char *cmd_name;
	void (*func)(char **command);
}
map_func;

/* builtin command */
void env(char **);
void ch_dir(char **);
void quit(char **);

/* shell utility */
void ctrl_C(int);
char *_getline(void);
char **tokenize(char *, const char *);
int is_delimeter(const char *, char);
void shell_execute(char **, int);
int check_command(char *);
void execute(char **, int);

/* shell printf or printer, helper */
int print(char *, int);
void (*get_func(char *))(char **);

/* shell string functions */
int _strlen(char *);
int _strcmp(char*, char *);

/*shell memory management */
void *_realloc(void *, int, int);

/* environment path */
char *_getenv(char *);

#endif /* SHELL_H */
