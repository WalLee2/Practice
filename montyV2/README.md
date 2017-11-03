# Monty Project
## Description:
The Monty project aims to help build understanding of what a stack and queue memory storage is. Understanding achieved through implementing many functionalities.
At a very high level, the program opens a file, reads the first line, tokenizes the individual members of the line and executes functions according to keywords or opcodes. The opcodes are what sets up the stack and queue storage.
### Usage:
./monty file

### Compilation:
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

|                  File                                    |                     Description                     |
| :-----------------------------------------: |  :-----------------------------------------------:  |
| add_node.c        |  Functions that add node to the beginning or end of a doubly LL.  |
| free_dllist.c     |  Frees a doubly linked list.  |
| main.c            |  Open a file, read line, pass the line to the tokenize func, error handle/clean up, and close the file.  |
| monty.h           |  Header file that contains all prototypes of functions used.  |
| num_check.c       |  Check to see if the string passed is actually a positive or negative number.  |
| op_add_sub_div_mul_mod.c  |  Contains arithmetic opcodes.  |
| op_pchar_pstr_rotl_rotr.c    |  Contains opcodes that convert the integer within the doubly linked list (DLL) into a character/string and opcodes that manipulate the DLL.  |
| op_push_pall_pint_pop_swap.c |  Contains opcodes that manipulate the DLL.  |
| opcode_check.c    |  Compares the token with each string in the array of structs and runs the appropriate function or returns an error and cleans up memory.  |
| parse_line.c      |  Tokenizes the line that's read from file passed from main.  |

### Example Usage:
```
wallee@ubuntu:~$ cat -e 01.m 
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
wallee@ubuntu:~$ ./monty 01.m
3
2
1
0
6
5
4
3
2
1
0
wallee@ubuntu:~$ 
```
