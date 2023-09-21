#include "monty.h"

bool isInteger(const char *str)
{
    char *endptr;
    
    strtol(str, &endptr, 10);

    while (*endptr != '\0')
    {
        if (!isspace(*endptr))
        {
            return false;
        }
        endptr++;
    }

    return true;
}

stack_t *createNode(int n)
{
    stack_t *node = malloc(sizeof(stack_t));

    if(node == NULL)
    errorHandler(5);

    node->n = n;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}


void handlePush(int n, unsigned int lineNumber)
{
    stack_t *node;

    node = createNode(n);
    
    pushFunc(&node, lineNumber);
}
