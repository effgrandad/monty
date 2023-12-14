#include "monty.h"

/**
 * print_char - displays the Ascii value.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int l_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, l_number);

	ascii = (*stack)->m;
	if (ascii < 0 || ascii > 127)
		string_err(10, l_number);
	printf("%c\n", ascii);
}

/**
 * print_str - displays a string.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @lyn: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int lyn)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->m;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates first node of the stack to the bottom.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @lyn: Interger representing by line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int lyn)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates last node of the stack to the top.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @lyn: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int lyn)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
