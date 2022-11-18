#include "shell.h"

/**
 *shell_execute - takes the command
 *
 *@command: the command argument
 *@cmd_type: type of command
 *
 *Return: void
 */

void shell_execute(char **command, int cmd_type)
{
	int stat;
	pid_t PID;

	if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
	{
		PID = fork();
		if (PID == 0)
		{
			execute(command, cmd_type);
		}
		if (PID < 0)
		{
			perror("failed to call fork");
			exit(1);
		}
		else
			wait(&stat);
	}
	else
		execute(command, cmd_type);
}

/**
 *check_command - checks what kind of command curretly executed
 *@command: the command passed
 *
 *Return: command found
 */
int check_command(char *command)
{
	int i = 0;
	char *int_cmd[] = {"exit", "cd", "env", NULL};

	while (command[i])
	{
		if (command[i] == '/')
			return (EXTERNAL_CMD);
		i++;
	}

	i = 0;
	while (int_cmd[i] != NULL)
	{
		if (_strcmp(command, int_cmd[i]) == 0)
			return (INTERNAL_CMD);
		i++;
	}
	return (INVALID_CMD);
}

/**
 *execute - execute command
 *@commands: the command passed
 *@cmd_type: the type of command passed
 */
void execute(char **commands, int cmd_type)
{
	void (*func)(char **command);  

	switch (cmd_type)
	{
		case EXTERNAL_CMD:
			{
				if (execve(commands[0], commands, NULL) == -1)
				{
					perror(_getenv("PWD"));
					exit(2);
				}
				break;
			}
		case INTERNAL_CMD:
			{
				func = get_func(commands[0]);
				func(commands);
				break;
			}
		case PATH_CMD:
			{
				break;
			}
		case INVALID_CMD:
			{
				break;
			}
	}
}
