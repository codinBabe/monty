#include "monty.h"
/**
 * u_err - handle usage error message
 * Return: FAILURE
 */

void u_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);

}

/**
 *o_err - handle open file error message
 *@file: file
 * Return: FAILURE
 */

void o_err(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);

	exit(EXIT_FAILURE);

}

/**
 * p_err - handles a push error
 * @file: file desciptor
 * @line: buffer
 * @head: head stack or queue
 * @line_num: line number of the command
 */

void p_err(FILE *file, char *line, stack_t *head, int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	fclose(file);
	free(line);
	free_stack(head);
	exit(EXIT_FAILURE);
}

/**
 * inst_err - Handle error for unknown instructions
 * @file: file descriptor
 * @line: buffer
 * @head:  head stack or queue
 * @line_num: line number of the command
 * @val: value
 */

void inst_err(FILE *file, char *line, stack_t *head, char *val, int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, val);
	fclose(file);
	free(line);
	free_stack(head);
	exit(EXIT_FAILURE);
}
