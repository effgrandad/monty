#include "monty.h"

/**
 * open_file - opens a file
 * @f_name: the file namepath
 * Return: void
 */
void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		err(2, f_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - divides every line into tokens so that you may choose
 * which function to call.
 * @buffer: line from file
 * @line_number: line number
 * @frmt:  storage format. If 0 Nodes will register as a stack.
 * if 1 nodes will register as a queue.
 * Return: Returns 0 if the opcode is stack. if queue, 1.
 */

int parse_line(char *buffer, int line_number, int frmt)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (frmt);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, frmt);
	return (frmt);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @l_n: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int l_n, int frmt)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_fun(func_list[j].f, opcode, value, l_n, frmt);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, l_n, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @l_n: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int l_n, int frmt)
{
	stack_t *node;
	int flag;
	int j = 0;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, l_n);
		for (; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				err(5, l_n);
		}
		node = create_node(atoi(val) * flag);
		if (frmt == 0)
			func(&node, l_n);
		if (frmt == 1)
			add_to_queue(&node, l_n);
	}
	else
		func(&head, l_n);
}
