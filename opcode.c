#include "monty.h"
/**
 * get_opcode - function that get opcode
 * @head: stack head
 * @args:arguments
 * @val:value to ge
 * @line_num: line number
 * Return: success or failure
 */
int get_opcode(stack_t **head, char *args, char *val, int line_num)
{
	int i = 0;

	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"_div", _div},
		{NULL, NULL}
	};

	while (opc[i].opcode)
	{
		if (!strcmp(args, opc[i].opcode))
		{
			if (!strcmp(args, "push"))
			{
				if (_isdigit(val) == 1)
					vals = atoi(val);
				else
					return (1);
			}
			opc[i].f(head, (unsigned int)line_num);
			break;
		}
		i++;
	}
	if (!opc[i].opcode)
		return (-1);
	return (0);
}
