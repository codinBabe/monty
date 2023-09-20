#include "monty.h"

/**
 * nop - function for the nop opcode
 * @head: head stack
 * @line_num: line number
 */
void nop(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
}

/**
 * swap - function that swap the top 2 elements of the stack
 * @head: head stack
 * @line_num: line number
 */
void swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int pos = 0;

	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		pos = temp->n;
		temp->n = temp->next->n;
		temp->next->n = pos;
	}
}

/**
 * add - funtion that add the top 2 elements of the stack
 * @head: head stack
 * @line_num: line number
 */
void add(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;
	int pos = 0;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	pos = (*head)->n;
	pos += (*head)->next->n;
	pop(head, line_num);
	temp->n = pos;
}
