# Monty

<img src="https://user-images.githubusercontent.com/69850751/167627200-66ee214c-b24f-4137-8306-ebcf03e7511e.png">



# Monty

name of the project → ****0x19. C - Stacks, Queues - LIFO, FIFO****

Project where we should implement ****Stacks, Queues - LIFO, FIFO in C language.****

### Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


**Monty byte code files**

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

**Learning Objetives**

-   What do LIFO and FIFO mean
-   What is a stack, and when to use it
-   What is a queue, and when to use it
-   What are the common implementations of stacks and queues
-   What are the most common use cases of stacks and queues
-   What is the proper way to use global variables



## Compilation & Output
* Your code will be compiled this way:
````
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
````

-   Any output must be printed on `stdout`
-   Any error message must be printed on `stderr`

## Usage examples and return

***doubly linked list representation of a stack (or queue)***
````c
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
````

***opcode and its function***
````c
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction;
````
  


## Use of the program:

-   Usage: `monty file`
    -   where `file` is the path to the file containing Monty byte code
-   If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
-   If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
    -   where `<file>` is the name of the file
-   If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
    -   where is the line number where the instruction appears.
    -   Line numbers always start at 1
-   The monty program runs the bytecodes line by line and stop if either:
    -   it executed properly every line of the file
    -   it finds an error in the file
    -   an error occured
-   If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
-   We have only use `malloc` and `free` for handle the memory.

# OPcode
operations that monty is able to execute, so these are the functions we use in our `.m files` to interact with the Stack and Queue

>Below we leave you the functions that our program runs and an example of use

## Push
The opcode `push`
 pushes an element to the stack.
 
 

## Pall
The opcode `pall`
prints all the values on the stack, starting from the top of the stack.

## Pint
The opcode `pint`
prints the value at the top of the stack, followed by a new line.

## Pop
The opcode `pop`
 removes the top element of the stack.

## Swap
The opcode `swap`
swaps the top two elements of the stack.

# #Add
The opcode `add`
adds the top two elements of the stack.

# Nop
The opcode `nop`
nop doesn’t do anything. :(


# Authors & Github accounts :
* [ Mauricio Heller ](https://github.com/hellerdejanuar) <br>
* [ Santiago Neira ](https://github.com/sanei1509)
