#include "shell.h"

/**
 * prompt - shell prompt
 *
 */
void prompt(void)
{
	if (isatty(0))
		write(1, "$ ", 2);
}
