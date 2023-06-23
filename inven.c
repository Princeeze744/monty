#include "monty.h"

/**
 * make_inventory - builds the inventory for each line
 * Return: inventory or NULL if malloc fails
 */
int make_inventory(void)
{

	inven = malloc(sizeof(inventory_t));
	if (!inventory)
	{
		fprintf(stderr, "Inventory build error message");
		return (EXIT_FAILURE);
	}

	inven->tail = NULL;
	inven->stack = NULL;
	inven->n = NULL;
	return (EXIT_SUCCESS);
}
