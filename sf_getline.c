#include "shell.h"

/**
 * _getline - gets a line of input
 *
 * Return: command line string command
 */
char *_getline()
{
	char *line = NULL;
	size_t n = 0;
	ssize_t c_count;

	c_count = getline(&line, &n, stdin);
	if (c_count == -1)
	{
		free(line);
		if (isatty(0))
			write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
