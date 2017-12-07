#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s {
	char *str;
	int strlen;
	struct list_s *next;
} list_t;

/** free **/
void _free_list(list_t **head);
void _free_all(list_t **head, char **arr_of_words, char *buf);

/** string manipulation **/
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src1, char *src2);

/** print **/
void print_ll(list_t *head);

/** Linked list **/
int add_to_linked_list(list_t **head, char *directory);
void ll_strcpy(char *dest, char *src);

/** shell functions **/
void tokenize_insert(char *buffer, char **array_of_words);
char *_getenv(const char *name);
int parse_directories_add(list_t **head, char *directories);
char *find_command(list_t **head, char *command, int len);
void append_execute(list_t **head, char **arr_of_words);
void execute(char *command, char **arr_of_words);


#endif
