#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line;

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
		printf("Standard input is not associated with terminal\n");
	}
	return (EXIT_SUCCESS);
}
