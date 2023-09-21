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
