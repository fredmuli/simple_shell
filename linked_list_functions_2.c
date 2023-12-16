#include "shell.h"

/**
 * free_from_tail - go to tail of the list and free memory
 * @node : current node
 */
void free_from_tail(list_t *node)
{
	if (node->next != NULL)
		free_from_tail(node->next);
	if (node->next == NULL)
	{
		free(node);
		return;
	}
}

/**
 * free_from_head - free memory from head of list
 * @node : current node
 */
void free_from_head(list_t *node)
{
	list_t *current = node;
	list_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current->len);
		free(current);
		current = next;
	}
}

/**
 * free_list - clear list and release memory
 * @head: head node pointer address
 */
void free_list(list_t *head)
{
	if (head != NULL)
		free_from_head(head);
}
