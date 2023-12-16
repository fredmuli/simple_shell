#include "shell.h"

/**
 * process_terminal_command - initiates the processing of command line string.
 * @line: line of command
 */
void process_terminal_command(char *line)
{
	char **env = environ;
	char **argv;
	int argc;

	if (*line == '\n' || line_is_all_space(line))
		return;
	argc = get_argc(line, " ");
	argv = (char **)malloc(argc * sizeof(char *));
	if (argv == NULL)
	{
		write(2, "Error: Issue with Arguments", 27);
		free(line);
		exit(EXIT_FAILURE);
	}
	split_str_to_argv(line, "\n ", argv, argc);
	command_switch(argc, argv, argv[0], env);
	free_array(argv);
}

/**
 * process_shell_command - process shell non interactive commands.
 * @argv: argument vectors
 */
void process_shell_command(char **argv)
{
	char **env = environ;
}

/**
 * create_child_process - create child process
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: Nothing
 */
void create_child_process(char **argv, char **env)
{
	int status;
	pid_t child_pid;
	pid_t pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: unable to create child process\n");
	}
	if (child_pid == 0)
	{
		execute_commmand(argv, env);
	}
	else
	{
		pid = waitpid(child_pid, &status, 0);
		if (pid == -1)
		{
			perror("Error: waitpid failed");
		}
		if (WIFEXITED(status))
		{
			printf("Child process exited normally\n");
		}
		else
		{
			printf("Child process did not exit normally\n");
		}
	}
	free_array(argv);
}

/**
 * execute_commmand - executes command
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: Nothing
 */
void execute_commmand(char **argv, char **env)
{
	if (execve(argv[0], argv, env) == -1)
	{
		perror("Error: Command execution failed\n");
	}
}

/**
 * command_switch - selects the commands to execute
 * @argc: argument count
 * @argv: argument vector
 * @cmd: command to run
 * @env: environment variables
 *
 * Return: Nothing
 */
void command_switch(int argc, char **argv, char *cmd, char **env)
{
	if (strcmp(argv[0], "exit") == 0)
		exit_shell(argv, argc);
	else if (strcmp(argv[0], "env") == 0)
		print_env(argv, env);
	else if (strcmp(argv[0], "getenv") == 0)
		print_env_var(argv, env);
	else if (strcmp(argv[0], "getpath") == 0)
		print_path(argv, env);
	else
		create_child_process(argv, env);
}
