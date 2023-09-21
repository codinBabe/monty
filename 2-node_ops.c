#include "monty.h"
/**
  *sub - function to sustrat
  *@head: stack head
  *@line_num: line_number
  *
  *Return: nothing to  return
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	int pos, nodes;

tmp = *head;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	pos = tmp->next->n - tmp->n;
	tmp->next->n = pos;
	*head = tmp->next;
	free(tmp);
}

/**
 * mul - multiplies the top two elements
 * @head: head pointer
 * @line_num: line number
 *
 * Return: nothing to return
 */
void mul(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}

#include "monty.h"

/**
 * mod - computes the rest of the division
 * @head: head pointer
 * @line_num: line number
 *
 * Return: nothing to return.
 */
void mod(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n % temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
