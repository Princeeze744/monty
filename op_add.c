#include "monty.h"

/**
 * add - adds the 2 top elements of a stack
 * @stack: stack
 * @line_num: line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	(void)line_num;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		op_error_exit_func();
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_num);
}
