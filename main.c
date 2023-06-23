#include "monty.h"

/**
 * main - entry point to the program
 * @argc: number of argument
 * @argv: arguments
 * Return: 0 if success
 */
int main(int argc, const char *argv[])
{
	unsigned int lcount;
	int fd;
	const char *monty_file;

	monty_file = argv[1];
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = open(monty_file, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		return (EXIT_FAILURE);
	}

	if (make_inventory() == EXIT_FAILURE)
		return (EXIT_FAILURE);

	lcount = 1;
	if (execute_line(fd, lcount) == EXIT_FAILURE)
	{
		all_free();
		return (EXIT_FAILURE);
	}

	all_free();
	return (EXIT_SUCCESS);
}
