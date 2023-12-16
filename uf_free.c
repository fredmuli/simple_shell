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
 * free_narray - Frees memory allocated to array
 * @buffer: array of pointers
 * @buffer_size: size of array
 *
 * Return: Nothing
 */
void free_narray(char **buffer, int buffer_size)
{
	unsigned int i = 0;

	if (buffer == NULL)
		return;
	for (i = 0; i < buffer_size; i++)
	{
		free(buffer[i]);
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
