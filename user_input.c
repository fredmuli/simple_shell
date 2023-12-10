#include "shell.h"

/**
 * read_command - Reads a command from standard input.
 * @command: Buffer to store the command.
 * @size: Size of the buffer.
 */
void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}

