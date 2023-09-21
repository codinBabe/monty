#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyCmd_s - monty command
 * @file: file descriptor
 * @line: line
 */

typedef struct montyCmd_s
{
	FILE *file;
	char *line;
} montyCmd_t;

extern int vals;
extern montyCmd_t montyCmd;

stack_t *create_node(int n);
void push(stack_t **head, unsigned int line_num);
void pall(stack_t **head, unsigned int line_num);
void pint (stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
void swap(stack_t **head, unsigned int line_num);
void add(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num)

void free_stack(stack_t *head);
void close_stack(stack_t **head);

void exec_instr(char *arg);
int get_opcode(stack_t **head, char *args, char *val, int line_num);
int _isdigit(char *s);
void u_err(void);
void o_err(char *file);
void p_err(FILE *file, char *line, stack_t *head, int line_num);
void inst_err(FILE *file, char *line, stack_t *head, char *val, int
 line_num);
#endif
