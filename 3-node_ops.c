#include "monty.h"

/**
 * _div - divides the top two elements of the stack.
 * @head: head pointer
 * @line_num: line number
 * Return: nothing to return
 */
void _div(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int pos = 0, result;

	temp = *head;
	
	while (temp)
	{
		temp = temp->next;
        	pos++;
	}

	if (pos < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num`);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n / temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
