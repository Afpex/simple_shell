#include "main.h"

/**
 * main - entry point to program
 * @ac: No of cmd-line arguments
 * @av: Array of cmd-line arguments
 * @env: Array of environ variables
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	else if (ac == 2 && _strcmp(av[1], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ac == 3 && _strcmp(av[1], "exit") == 0)
	{
		int status = atoi(av[2]);
		exit (status);
	}
	else
	{
		_puts_stderr("...not found\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
