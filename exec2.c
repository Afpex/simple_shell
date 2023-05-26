#include "main.h"

/**
 * handle_alias_command - Handles the "alias" command by printing aliases
 *                        or handling individual aliases provided as arguments.
 *
 * @argv: Array of command-line arguments
 */

void handle_alias_command(char **argv)
{
	if (argv[1] == NULL)
	{
		print_all_aliases();
	}
	else
	{
		int z = 1;

		while (argv[z] != NULL)
		{
			handle_single_alias(argv[z]);
			z++;
		}
	}
}

/**
 * print_all_aliases - Prints all aliases.
 */

void print_all_aliases(void)
{
	_puts("Printing all aliases\n");
}

/**
 * handle_single_alias - Handles an individual alias.
 *
 * @arg: Alias argument to handle
 */

void handle_single_alias(char *arg)
{
	char buffer[100];

	_snprintf(buffer, sizeof(buffer), "Handling alias: %s\n", arg);
	_fputs(buffer, STDOUT_FILENO);
}
