#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void);

/**
 * print - Prints a message to the standard output.
 * @msg: The message to be printed.
 */
void print(const char *msg);

/**
 * read_command - Reads a command from standard input.
 * @command: Buffer to store the command.
 * @size: Size of the buffer.
 */
void read_command(char *command, size_t size);

/**
 * execute_command - Executes a command using fork and execvp.
 * @command: The command to execute.
 */
void execute_command(const char *command);
#endif /* SHELL_H */

