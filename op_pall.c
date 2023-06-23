#include "monty.h"

/**
 * pall - prints all d value on d stack starting from d top stack
 * @head: pointer to head pointer
 * @line_num: line_number
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *curr;
	(void)line_num;

	curr = *head;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
