#include "monty.h"

void openFile(char *fileName)
{
    if (fileName == NULL)
    errorHandler(2, fileName);
    else
    {
        FILE *fd = fopen(fileName, "r");
        if (fd == NULL)
        errorHandler(2, fileName);
        else
        {
            readFile(fileName, fd);   
        }
    }

}

void readFile(__attribute__((__unused__)) char *fileName, FILE *fd)
{
    unsigned int lineNumber = 0;
    char line[1000];

    while (fgets(line, sizeof(line), fd) != NULL)
    {
        lineNumber++;

        if((strcmp(line, "\n") == 0))
        continue;

        removeExtraSpaces(line);

        if(strlen(line) == 1)
        continue;
        
        mnupilateReadedLine(line, lineNumber);
    }

     fclose(fd);   
}

void removeExtraSpaces(char str[])
{
    int i, j;
    int spaceFlag = 0;

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            if (!spaceFlag) {
                str[j++] = ' ';
                spaceFlag = 1;
            }
        } else {
            str[j++] = str[i];
            spaceFlag = 0;
        }
    }

    str[j] = '\0';
}


void mnupilateReadedLine(char line[], unsigned int lineNumber)
{
    char *token;

    int tokenCount = 1;

    token = strtok(line, " ");
    if (strcmp(token, "push") == 0)
    {
        while (token != NULL)
        {
            tokenCount++;
            token = strtok(NULL, " ");

            if (token == NULL)
            {
                tokenCount --;
                break;
            }

            if(!isInteger(token))
            errorHandler(4, lineNumber);

            if(tokenCount == 2)
            break;
 
        }

        if (tokenCount != 2)
        errorHandler(4, lineNumber);
        else
        {
            handlePush(atoi(token), lineNumber);
        }
    }
    else
    findtheFunction(token, lineNumber);
}


void findtheFunction(char *opCode, unsigned int lineNumber)
{
    long unsigned int i;
    int done = 0;
    instruction_t instructions[] = {{"pall", pallFunc},
    {"pint", pintFunc}, {"pop", popFunc},
    {"swap", swapFunc}, {"add", addFunc}, {"nop", doNothing},
    {"sub", subFunc}, {"div", divFunc}, {"mul", mulFunc},
    {"mod", modFunc}, {"#", commentFunc}, {"pchar", pcharFunc},
    {"pstr", pstrFunc}, {"rotl", rotlFunc}};

    for (i = 0; i < 14 ; i++)
    {
        if(strcmp(opCode, instructions[i].opcode) == 0)
        {
            instructions[i].f(&head, lineNumber);
            done = 1;
        }

        if (done)
        break;
       
    }
    if(done == 0)
    {
        errorHandler(3, lineNumber, opCode);
    }
   
}
