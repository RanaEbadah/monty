#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: arguments list
 * Return: always 0
 */
int main(int argc, char *argv[])
{

    if (argc != 2)
    errorHandler(1);
    else
    {
        openFile(argv[1]);
    }

    return (0);
}
