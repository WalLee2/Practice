# Monty Project
## Description:
The monty program opens up a file, reads each line, and executes functions according to certain keywords or opcodes that it reads. The monty program will continue to read each line until the end of the file.
### Usage:
./monty file

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
