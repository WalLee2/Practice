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
        void (*f)(stack_t **, unsigned int);
} instruction_t;
extern int error;
int parse_line(char *buff, stack_t **head, unsigned int l_num);
int num_check(char *str, unsigned int l_num);
int opcode_check(char *tok, stack_t **head, unsigned int l_num);
void m_push(stack_t **head, unsigned int num);
void m_pall(stack_t **head, unsigned int l_num);
void m_pint(stack_t **head, unsigned int l_num);
void m_pop(stack_t **head, unsigned int l_num);
void m_swap(stack_t **head, unsigned int l_num);
void m_add(stack_t **head, unsigned int l_num);
void free_dllist(stack_t **head);
#endif
