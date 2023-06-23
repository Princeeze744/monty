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

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	if (make_inventory() == EXIT_FAILURE)
		return (EXIT_FAILURE);

	lcount = 1;
	if (execute(fd, lcount) == EXIT_FAILURE)
	{
		free_all();
		return (EXIT_FAILURE);
	}

	free_all();
	return (EXIT_SUCCESS);
}
