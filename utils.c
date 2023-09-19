#include "monty.h"

/**
 * _isdigit - checks if a num is digit
 * Return: 0 or 1
 * @s: Value
 **/

int _isdigit(char *s)
{
	char *temp = s;

	if (s == NULL)
		return (0);
	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if ((*temp < '0' || *temp > '9'))
		{
			return (0);
		}
	}
	return (1);
}
