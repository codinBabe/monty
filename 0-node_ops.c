#include "monty.h"

int vals;
/**
 */
stack_t *create_node(int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 */
void push(stack_t **head, unsigned int line_num)
{
	stack_t *new_node = NULL;
	(void)line_num;

	new_node = create_node(vals);
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;
	(void)line_num;

	temp = *head;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 */
void pint (stack_t **head, unsigned int line_num)
{
	if  (!*head || !head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		close_stack(head);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*head)->n);
}

/**
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if(!*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*head)->next;
		free(*head);
		if (temp)
			temp->prev = NULL;
		*head = temp;
	}
}
