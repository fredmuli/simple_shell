#include "shell.h"

/**
 * _get_env - gets environment variable
 * @env: array of environment variables
 * @name: name of variable
 *
 * Return: value of environment variable
 */
char *_get_env(char **env, const char *name)
{

	int i = 0;
	char *key = NULL;
	char *val = NULL;
	char *copy;

	while (env[i])
	{
		copy = strdup(env[i]);
		key = strtok(copy, "=");
		val = strtok(NULL, "=");
		if (strcmp(name, key) == 0)
		{
			val = strdup(val);
			free(copy);
			return (val);
		}
		i++;
	}
	return (NULL);
}
