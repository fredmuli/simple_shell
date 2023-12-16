#include "shell.h"

/**
 * print_env_var - prints an environment variable
 * @argv: arguments vector
 * @env: array of environment variables
 *
 * Return: value of environment variable
 */
void print_env_var(char **argv, char **env)
{
	char *val;

	if (argv[1] != NULL)
	{
		val = _get_env(env, argv[1]);
		if (val)
		printf("%s\n", val);
	}
}
