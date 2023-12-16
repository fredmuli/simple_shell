#include "shell.h"

/**
 * line_is_all_space - check if user enters only white space
 * @line: command line string
 *
 * Return: 1 on success, 0 on failure
 */
int line_is_all_space(char *line)
{
	int i = 0;

	line[strlen(line) - 1] = '\0';
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
