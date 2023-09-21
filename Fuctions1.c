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

void pintFunc(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    errorHandler(6, line_number);

    printf("%d\n", (*stack)->n);
}

void popFunc(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (stack == NULL)
    errorHandler(7, line_number);

    temp = *stack;

    *stack = temp->next;
    if(*stack != NULL)
    (*stack)->prev = NULL;

    free(temp);
}

void swapFunc(stack_t **stack, unsigned int line_number)
{
    stack_t *temp1, *temp2;

    if ((*stack == NULL) || ((*stack)->next == NULL))
    errorHandler(8, line_number);

    temp1 = *stack;
    temp2 = (*stack)->next;


    temp1->next = temp2->next;
    temp1->prev = temp2;

    temp2->prev = NULL;
    temp2->next = temp1; 

    *stack = temp2;

}

void addFunc(__attribute__((__unused__)) stack_t **stack, __attribute__((__unused__)) unsigned int line_number)
{
    printf("add\n");
}
