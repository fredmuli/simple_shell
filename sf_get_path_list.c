#include "shell.h"

/**
 * get_path_list - get a linked list of PATH
 * @env: environment variable array
 *
 * Return: The head node of the linked list
 */

list_t *get_path_list(char **env)
{
	list_t *head;
	char *path = strdup(_get_env(env, "PATH"));
	char *token;

	head = malloc(sizeof(list_t));
	if (head == NULL)
	{
		free(path);
		return (NULL);
	}
	token = strtok(path, ":");
	if (token)
	{
		head->str = strdup(token);
		head->len = strlen(token);
		head->next = NULL;

		do {
			token = strtok(NULL, ":");
			if (token)
				add_node_end(&head, token);
		} while (token != NULL);
	}
	free(path);
	return (head);
}
