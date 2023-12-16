#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/**
 * struct list_s - singly linked list
 * @str: string value
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
};
/**
 * list_t - typedef for list_s
 */
typedef struct list_s list_t;
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
list_t *get_path_list(char **env);

/* System Functions */
void prompt(void);
char *_getline(void);
void process_terminal_command(char *line);
void process_shell_command(char **argv);
void create_child_process(char **argv, char **env);
void execute_commmand(char **argv, char **env);
void command_switch(int argc, char **argv, char *cmd, char **env);
void exit_shell(char **argv, int argc);
void print_env(char **argv, char **env);
void print_env_var(char **argv, char **env);
void print_path(char **argv, char **env);

/* Utility Functions */
int get_argc(char *line, const char *delim);
int count_argv(char **argv);
void split_str_to_argv(char *line, const char *delim, char **argv, int argc);
int line_is_all_space(char *line);
char *_get_env(char **env, const char *name);

void free_array(char **buffer);
void free_narray(char **buffer, int buffer_size);
void free_array_exit(char **buffer);

#endif /*SHELL_H*/
