#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *line;
	char buffer[1024];

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			prompt();
			line = _getline();
			process_terminal_command(line);
			free(line);
		}
	}
	else
	{
		if (fgets(buffer, 1024, stdin) != NULL)
		{
			process_terminal_command(buffer);
		}
	}
	return (EXIT_SUCCESS);
}
