#include "monty.h"

/**
 * swap - swap the top 2 elements of the stack
 * @stack: stack
 * @line_num: line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		op_error_exit_func();
	}

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}
