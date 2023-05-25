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
	int status = 0;
	
	if (ac == 1)
		prompt(av, env);
	else if (ac == 2)
		status = atoi(av[1]);

	printf("Exit status: %d\n", status);

	return (status);
}
