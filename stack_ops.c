#include "monty.h"

/**
 * mul_nodes - sums top two elements of the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int l_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->m * (*stack)->prev->m;
	(*stack)->m = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - sums top two elements of the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int l_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, l_number, "mod");


	if ((*stack)->m == 0)
		more_err(9, l_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->m % (*stack)->prev->m;
	(*stack)->m = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
