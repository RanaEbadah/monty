#include "monty.h"
stack_t *mystack;

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: arguments list
 * Return: always 0
 */

int main(int argc, char *argv[])
{
    mystack = malloc(sizeof(stack_t));
    mystack->n = 0;
    mystack->next = NULL;
    mystack->prev = NULL;
    
    if (argc != 2)
    errorHandler(1);
    else
    {
        openFile(argv[1]);
    }

    return (0);
}
