#include "shell.h"

/**
 * print_path - print PATH list
 * @argv: argument vector
 * @env: environment variables
 */
void print_path(char **argv, char **env)
{
	list_t *head = get_path_list(env);

	print_list(head);
	free_list(head);
}
