#include "monty.h"

void doNothing(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    return;
}

void subFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    int firstn;

    if ((*stack == NULL) || ((*stack)->next == NULL))
    errorHandler(10, line_number);

    firstn = (*stack)->n;

    popFunc(stack, line_number);

    (*stack)->n -= firstn;
}

void divFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("div\n");
}

void mulFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("mul\n");
}

void modFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("mod\n");
}
