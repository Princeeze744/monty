#include "monty.h"

/**
 * push - push a node to the stack
 * @hd: pointer to head pointer
 * @line_num: line number
 */
void push(stack_t **hd, unsigned int line_num)
{
	int n;
	stack_t *new;
	(void)line_num;

	n = conv_to_int(inven->n);
	if (n == 'a')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		op_error_exit_func();
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		op_error_exit_func();
	}

	new->prev = NULL;
	new->next = *hd;
	new->n = n;

	if (!(*hd))
		inven->tail = new;
	*hd = new;
}
