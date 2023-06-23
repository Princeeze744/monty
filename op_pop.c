#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: stack head
 * @line_num: line number
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		op_error_exit_func();
	}

	temp = *head;
	*head = (*head)->next;
	free(temp);
}
