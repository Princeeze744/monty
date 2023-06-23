#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/* structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer data
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct inventory_s - inventory structure
 * @code: code from parseln function
 * @input: int data
 */
typedef struct inventory_s
{
	char *code;
	char *n;
	stack_t *stack;
	stack_t *tail;
	char *line;
} inventory_t;

/* global variable */
extern inventory_t *inven;
inventory_t *inven;

/* op functions */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/* Utility functions */
char *readln(int);
void (*get_func(char *))(stack_t **, unsigned int);
int make_inventory(void);
int parseln(char *);
int execute_line(int, unsigned int);
int conv_to_int(char *);
void all_free();
void free_stack(void);
void free_inventory(void);
void op_error_exit_func(void);

#endif /* MAIN_H */
