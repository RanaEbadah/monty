#include "monty.h"

void pallFunc(stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    stack_t *temp;

    temp = *stack;

    if(temp == NULL)
    return;

    while (temp->next != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
    printf("%d\n", temp->n);

}

void pintFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("pint\n");
}

void popFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("pop\n");
}

void swapFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("swap\n");
}

void addFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("add\n");
}
