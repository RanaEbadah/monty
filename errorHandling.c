#include "monty.h"
/*
* 1 -> USAGE: monty file
* 2 -> can not open the file
* 3 -> unknown instruction
* 4 -> push integer
* 5 -> memory allocation failed
*/
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
    case 5:
        fprintf(stderr, "Error: malloc failed\n");
        break;
    default:
        break;
    }

    va_end(ag);
    exit(EXIT_FAILURE);
}
