#include "monty.h"

/**
 * add_to_stack - Adds  node to the stack.
 * @new_node: Pointer to the new node.
 * @lyn: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int lyn)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * print_stack - sums a node to the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;

	(void) l_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_top - sums a node to the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, l_number);

	temp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top - displays the top node of the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, l_number);
	printf("%d\n", (*stack)->n);
}
