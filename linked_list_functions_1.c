#include "shell.h"

/**
 * print_list - prints all elements of a linked list.
 * @h: head node pointer.
 * Return: Returns the size of the linked list.
 */
size_t print_list(const list_t *h)
{
	if (h)
	{
		if (h->str == NULL)
			printf("%s\n", "(nil)");
		else
			printf("%s\n", h->str);
		return (1 + print_list(h->next));
	}
	return (0);
}

/**
 * list_len - gets a length of the linked list..
 * @h: head node pointer.
 * Return: Returns the size of the linked list.
 */
size_t list_len(const list_t *h)
{
	if (h)
		return (1 + list_len(h->next));
	return (0);
}

/**
 * add_node - Adds a node to the front of the linked list.
 * @head: head node pointer address.
 * @str: string value
 * Return: Returns the address of the new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	new->str = strdup(str);
	new->len = strlen(str);
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		*head = new;
		new->next = temp;
	}
	return (new);
}

/**
 * add_to_tail - add new node to tail of the list
 * @node : current node
 * @new : new node
 *
 */
void add_to_tail(list_t *node, list_t *new)
{
	if (node->next == NULL)
		node->next = new;
	else
	{
		add_to_tail(node->next, new);
		return;
	}
}

/**
 * add_node_end - Adds a node to the front of the linked list.
 * @head: head node pointer address.
 * @str: string value
 * Return: Returns the address of the new element.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = strlen(str);
	if (*head == NULL)
		*head = new;
	else
		add_to_tail(*head, new);
	return (new);
}

