#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0.
 */

int main(void)
{
	char command[128];

	while (true)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}

	return (0);
}

/**
 * find - Finds a command in PATH.
 * @info: Pointer to the parameter & return info struct.
 *
 * Return: void
 */
void find(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];

	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}

	for (i = 0, k = 0; info->arg[i]; i++)
	{
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	}

	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=") ||
			info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
		{
			fork_cmd(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork - Forks an exec thread to run cmd.
 * @info: Pointer to the parameter & return info struct.
 *
 * Return: void
 */
void fork(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}

	wait(&(info->status));
	if (WIFEXITED(info->status))
	{
		info->status = WEXITSTATUS(info->status);
		if (info->status == 126)
			print_error(info, "Permission denied\n");
	}
}
