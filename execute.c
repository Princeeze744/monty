#include "monty.h"

/**
 * execute_line - execute each line of code recursively
 * @fd: file descriptor
 * @line_num: line number
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int execute_line(int fd, unsigned int line_num)
{
	char *buff;
	void (*func)(stack_t **, unsigned int);

	buff = readln(fd);
	if (!buff)
	{
		free(buff);
		return (EXIT_SUCCESS);
	}

	inven->code = NULL;
	inven->n = NULL;

	parseln(buff);

	if (!inven->code)
	{
		line_num++;
		free(buff);
		return (execute(fd, line_num));
	}

	func = get_op_func(inven->code);
	if (!func)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_num, inven->code);
		free(buff);
		return (EXIT_FAILURE);
	}

	inven->line = buff;
	func(&inven->stack, line_num++);

	free(buff);
	return (execute(fd, line_num++));
}
