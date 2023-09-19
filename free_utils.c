#include "monty.h"

/**
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
