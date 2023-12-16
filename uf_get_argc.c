#include "shell.h"

/**
 * get_argc - get the count of argument vector items
 * @line: command line string
 * @delim: delimeter to use to split string
 *
 * Return: count of argument vector items
 */
int get_argc(char *line, const char *delim)
{
	char *token;
	int count = 0;
	char *line_cpy = strdup(line);

	token = strtok(line_cpy, delim);
	count++;
	while ((token = strtok(NULL, delim)))
		count++;
	free(line_cpy);
	return (count);
}

/**
 * count_argv - counts the number of arguments in an arg vector
 * @argv: argument vector
 *
 * Return: count of argument vector items
 */
int count_argv(char **argv)
{
	int c = 0;

	while (*(argv + c) != NULL)
		c++;
	return (c);
}
