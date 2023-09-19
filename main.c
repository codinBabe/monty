#include "monty.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: success or failure
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{

		u_err();
	}
	else
	{
		exec_instr(argv[1]);
	}

	return (EXIT_SUCCESS);

}
