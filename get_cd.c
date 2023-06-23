#include "monty.h"

/**
 * readln - reads a line from a file
 * @fd: file descriptor
 * Return: one line from file
 */
char *readln(int fd)
{
	char buf, *buffer;
	int n_read;

	buf = '\0';

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed");
		return (NULL);
	}
	buffer[0] = '\0';

	n_read = 1;
	while (n_read > 0)
	{
		n_read = read(fd, &buf, 1);
		if (buf == '\n')
			return (buffer);

		strncat(buffer, &buf, 1);
	}


	free(buffer);
	return (NULL);
}

/**
 * parseln - Gets opcode and data from line
 * @ln: line
 * Return: inventory
 */
int parseln(char *ln)
{
	char *delimiter;

	delimiter = "\n\t ";
	inven->code = strtok(ln, delimiter);
	inven->n = strtok(NULL, delimiter);

	return (EXIT_SUCCESS);
}
