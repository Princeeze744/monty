#include "monty.h"

/**
 * op_error_exit - exits program on op error
 */
void op_error_exit_func(void)
{
	free(inven->line);
	all_free();
	exit(EXIT_FAILURE);
}
