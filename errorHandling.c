#include "monty.h"
/*
* 1 -> USAGE: monty file
* 2 -> can not open the file
* 3 -> unknown instruction
* 4 -> push integer
* 5 -> memory allocation failed
* 6 -> can't pint, stack empty
* 7 -> can't pop an empty stack.
* 8 -> can't swap, stack too short.
* 9 ->  can't add, stack too short
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
    case 6:
        fprintf(stderr,"L%u: can't pint, stack empty\n", va_arg(ag, unsigned int));
        break;
    case 7:
        fprintf(stderr,"L%u: can't pop an empty stack\n", va_arg(ag, unsigned int));
        break;
    case 8:
        fprintf(stderr, "L%u: can't swap, stack too short\n", va_arg(ag, unsigned int));
        break;
    case 9:
        fprintf(stderr, "L%u: can't add, stack too short\n", va_arg(ag, unsigned int));
        break;
    default:
        break;
    }

    va_end(ag);
    free_nodes();
    exit(EXIT_FAILURE);
}

void free_nodes()
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
