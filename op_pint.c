#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head of a stack
 * @line_number: line_number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	(void)line_num;

	curr = *stack;

	if (!curr)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		op_error_exit_func();
	}

	printf("%d\n", curr->n);
}
