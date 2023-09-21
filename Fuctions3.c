#include "monty.h"

void commentFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("comment\n");
}

void pcharFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("pchar\n");
}

void pstrFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("pstr\n");
}

void rotlFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("rotl\n");
}

void pushFunc(stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    if (head == NULL)
    head = *stack;
    else
    {
        (*stack)->next = head;
        head = *stack;
    }
}
