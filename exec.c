#include "monty.h"

montyCmd_t montyCmd = {NULL, NULL};

/**
 *exec_instr - reads the file and executes the monty byte instruction
 *@arg: arguments
 */

void exec_instr(char *arg)
{
	int c = 0, rd = 0;
	size_t bufsize = 0;
	char *token = NULL, *val = NULL;
	stack_t *head = NULL;

	montyCmd.file = fopen(arg, "r");
	if (montyCmd.file)
	{
		while (getline(&montyCmd.line, &bufsize, montyCmd.file) != -1)
		{
			c++;
			token = strtok(montyCmd.line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
				continue;
			val = strtok(NULL, " \n\t\r");
			rd = get_opcode(&head, token, val, c);
			if (rd == 1)
				p_err(montyCmd.file, montyCmd.line, head, c);
			else if (rd == -1)
				inst_err(montyCmd.file, montyCmd.line, head, token, c);
		}
		free(montyCmd.line);
		free_stack(head);
		fclose(montyCmd.file);
	}
	else
	{

		o_err(arg);

	}
}
