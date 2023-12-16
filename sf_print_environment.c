#include "shell.h"

/**
 * print_env - print environmental variables
 * @argv: argument vector
 * @env: environment variables
 */
void print_env(char **argv, char **env)
{
	int i = 0;
	int l = 0;

	while (env[i])
	{
		l = strlen(env[i]);
		write(STDOUT_FILENO, env[i], l);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
