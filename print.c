#include "shell.h"

/**
 * print - Prints a message to the standard output.
 * @msg: The message to be printed.
 */
void print(const char *msg)
{
	write(STDOUT_FILENO, msg, strlen(msg));
}
