#include "monty.h"

int vals;
/**
 * create_node - function that create node
 * @n:data to store
 * Return:new_node
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
 * push - function that push value onto the stack
 * @head:head stack
 * @line_num:line number
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
 * pall - function to print all values in the stack
 * @head: head stack
 * @line_num:line number
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
 * pint - function that print the top value of the stack
 * @head: head stack
 * @line_num: line number
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
 * pop - function that pop a value from the stack
 * @head:head stack
 * @line_num: line number
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (!*head)
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
