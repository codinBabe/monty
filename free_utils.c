#include "monty.h"

/**
 * free_stack - function that free stack node
 * @head: stack head
 */
void free_stack(stack_t *head)
{
	stack_t *temp = head;

	if (temp != NULL)
	{
		free_stack(temp->next);
		free(temp);
	}
}

/**
 * close_stack - function that close and clean file
 * @head: stack head
 */
void close_stack(stack_t **head)
{
	stack_t *temp = *head;

	while (temp)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	fclose(montyCmd.file);
	free(montyCmd.line);
}
