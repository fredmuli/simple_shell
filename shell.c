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
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		line = _getline();
		process_terminal_command(line);
	}
	return (EXIT_SUCCESS);
}
