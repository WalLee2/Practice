#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **, unsigned int);
} instruction_t;
int parse_line(char *buff, stack_t **head, unsigned int l_num, int *state);
int num_check(char *str, unsigned int l_num);
int opcode_check(char *tok, stack_t **head, unsigned int l_num);
int add_node_begin(stack_t **head, int num);
int add_node_end(stack_t **head, int num);
/*opcode function prototypes*/
int m_push(stack_t **head, int num, int *state);
int m_pall(stack_t **head, unsigned int l_num);
int m_pint(stack_t **head, unsigned int l_num);
int m_pop(stack_t **head, unsigned int l_num);
int m_swap(stack_t **head, unsigned int l_num);
int m_add(stack_t **head, unsigned int l_num);
int m_sub(stack_t **head, unsigned int l_num);
int m_div(stack_t **head, unsigned int l_num);
int m_mul(stack_t **head, unsigned int l_num);
int m_mod(stack_t **head, unsigned int l_num);
int m_pchar(stack_t **head, unsigned int l_num);
int m_pstr(stack_t **head, unsigned int l_num);
int m_rotl(stack_t **head, unsigned int l_num);
int m_rotr(stack_t **head, unsigned int l_num);
/*free doubly linked list*/
void free_dllist(stack_t **head);
#endif
