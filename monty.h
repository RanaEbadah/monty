#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>

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

extern stack_t *head;

/* FileOps*/
void openFile(char *fileName);
void readFile(char *fileName, FILE *fd);
void removeExtraSpaces(char str[]);
void mnupilateReadedLine(char line[], unsigned int lineNumber);
void findtheFunction(char *opCode, unsigned int lineNumber);


/*errorHandling*/
void errorHandler(int errId, ...);
void free_nodes();


/*functions1.c*/
void pallFunc(stack_t **stack, unsigned int line_number);
void pintFunc(stack_t **stack, unsigned int line_number);
void popFunc(stack_t **stack, unsigned int line_number);
void swapFunc(stack_t **stack, unsigned int line_number);
void addFunc(stack_t **stack, unsigned int line_number);

/*Fuctions2.c*/
void doNothing(stack_t **stack, unsigned int line_number);
void subFunc(stack_t **stack, unsigned int line_number);
void divFunc(stack_t **stack, unsigned int line_number);
void mulFunc(stack_t **stack, unsigned int line_number);
void modFunc(stack_t **stack, unsigned int line_number);

/*Functions3.c*/
void commentFunc(stack_t **stack, unsigned int line_number);
void pcharFunc(stack_t **stack, unsigned int line_number);
void pstrFunc(stack_t **stack, unsigned int line_number);
void rotlFunc(stack_t **stack, unsigned int line_number);
void pushFunc(stack_t **stack, __attribute__((__unused__)) unsigned int line_number);


/*Functions4.c*/
bool isInteger(const char *str);
stack_t *createNode(int n);
void handlePush(int n, unsigned int lineNumber);

#endif /* MONTY_H */
