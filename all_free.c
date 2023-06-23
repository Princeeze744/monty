#include "monty.h"

/**
 * all_free - free all alloc'd memory
 */
void all_free(void)
{
	free_stack();
	free_inventory();
}

/**
 * free_stack - free stack
 */
void free_stack(void)
{
	stack_t **curr, *temp;

	curr = &inven->stack;
	while (*curr)
	{
		temp = *curr;
		*curr = (*curr)->next;
		free(temp);
	}
}

/**
 * free_inventory - free inventory
 */
void free_inventory(void)
{
	free(inven);
}
