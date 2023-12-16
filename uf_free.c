#include "shell.h"

/**
 * free_array - Frees memory allocated to array
 * @buffer: array of pointers
 *
 * Return: Nothing
 */
void free_array(char **buffer)
{
	unsigned int i = 0;

	if (buffer == NULL)
		return;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

/**
 * free_array_exit - Frees memory allocated to array
 * @buffer: array of pointers
 *
 * Return: Nothing
 */
void free_array_exit(char **buffer)
{
	unsigned int i = 0;

	if (buffer == NULL)
		return;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	exit(EXIT_FAILURE);
}
