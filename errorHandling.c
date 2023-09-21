#include "monty.h"

void errorHandler(int errId, ...)
{
    va_list ag;

    va_start(ag, errId);
    switch (errId)
    {
    case 1:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case 2:
        fprintf(stderr,"Error: Can't open file %s\n", va_arg(ag, char *));
        break;
    case 3:
        fprintf(stderr, "L%u: ", va_arg(ag, unsigned int));
        fprintf(stderr, "unknown instruction %s\n", va_arg(ag, char*));
        break;
    case 4:
        fprintf(stderr,"L%u: usage: push integer\n", va_arg(ag, unsigned int));
        break;
    default:
        break;
    }

    va_end(ag);
    exit(EXIT_FAILURE);
}
