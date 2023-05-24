#include "main.h"

/**
 * space_check - Checks if a string consists only of spaces and tabs
 * @lineptr: The string to check
 *
 * Return: 1 if the string contains only spaces and tabs, 0 otherwise
 */
int space_check(char *lineptr)
{
	int a;

	for (a = 0; lineptr[a] != '\n'; a++)
	{
		if (lineptr[a] != ' ' && lineptr[a] != '\t')
			return (0);
	}
	return (1);
}

/**
 * init_path - Initializes/populates the array of PATH dirs by extracting the
 *             the dirs from "PATH" ENVIRON VAR
 * @path_index: Pointer to the variable storing the number of PATH directories
 * @path_parts: Array to store the PATH directories
 *
 */

void init_path(int *path_index, char *path_parts[])
{
	char *path = _getenv("PATH");
	char *part = strtok(path, ":");

	while (part != NULL && *path_index < MAX_COMMAND)
	{
		path_parts[(*path_index)++] = part;
		part = strtok(NULL, ":");
	}
}

/**
 * prompt - Displays the shell prompt and handles user input
 * @av: command-line arguments
 * @env: environment variables
 */

void prompt(char **av, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_COMMAND];
	int path_index = 0;
	char *path_parts[MAX_COMMAND];
	int argc;
	char *token;

	(void) av;

	init_path(&path_index, path_parts);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell$ ", 7);

		num_char = getline(&lineptr, &n, stdin);
		if (space_check(lineptr) == 1)
		{
			lineptr = NULL;
		}
		if (num_char == -1)
		{
			write(STDOUT_FILENO, "\n", 2);
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		if (lineptr != NULL)
		{
			lineptr[_strcspn(lineptr, "\n")] = '\0'; /* Remove newline */

			argc = 0;
			token = strtok(lineptr, " ");
			while (token != NULL && argc < MAX_COMMAND - 1)
			{
				argv[argc++] = token;
				token = strtok(NULL, " ");
			}
			argv[argc] = NULL; /* Set the last element to NULL */
			handle_cmd(argv, env, path_parts, path_index);
		}
		
	}
}

