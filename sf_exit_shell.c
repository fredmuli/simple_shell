#include "shell.h"

/**
 * exit_shell - exit the shell program
 * @argv: argument vector
 * @argc: argument count
 */
void exit_shell(char **argv, int argc)
{
	int status;

	if (argc >= 2)
	{
		status = atoi(argv[1]);
		free_array(argv);
		exit(status);
	}
	free_array(argv);
	exit(EXIT_SUCCESS);
}
