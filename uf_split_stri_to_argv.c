#include "shell.h"

/**
 * split_str_to_argv - Split command string into an argument vector
 * @line: command line string
 * @delim: delimeter to use to split string
 * @argv: pointer to arguement vector
 * @argc: count of argument vector items
 *
 * Return: Nothing
 */
void split_str_to_argv(char *line, const char *delim, char **argv, int argc)
{
	char *line_cpy;
	int i = 0;

	if (argc >= 1)
	{
		line_cpy = strdup(line);
		argv[i] = strdup(strtok(line_cpy, delim));
		for (i = 1; i < argc; i++)
		{
			argv[i] = strdup(strtok(NULL, delim));
		}
		free(line_cpy);
	}
}
