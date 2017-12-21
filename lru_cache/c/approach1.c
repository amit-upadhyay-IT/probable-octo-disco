#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void printAux(char *aux, int c_size)
{
    printf("\n");
    int i;
    for (i = 0; i < c_size; ++i)
    {
        if (aux[i] >= 48 && aux[i] <= 58)
            printf("%d\n", aux[i]-48);
        else
            printf("%d\n", aux[i]);
    }
    printf("\n");
}

int findOutBlock(char *aux, char key, int c_size)
{
    int i;
    for (i = 0; i < c_size; ++i)
        if (key == aux[i])
            return 1;
    return 0;
}

int getFoundIndex(char *aux, int key, int c_size)
{
    int i;
    for (i = 0; i < c_size; ++i)
        if (key == aux[i])
            return i;
    return -1;
}

void replaceBlock(char* aux, char next, int c_size, int *faultCnt)
{
    int isBlockAvailable = findOutBlock(aux, next, c_size);

    if (isBlockAvailable)
    {
        // here I want to put the found block on the front.
        // so for this I would find the index of found block, then from its left
        // I would shift right each element by 1, at last I would put found block at 0 index
        int foundIndex = getFoundIndex(aux, next, c_size);
        if (foundIndex != -1)
        {
            int i;
            for (i = foundIndex-1; i >= 0; --i)
            {
                aux[i+1] = aux[i];
            }
            aux[0] = next;
        }
        else
        {
            printf("\nSomething went wrong!\n");
        }
        return ;
    }
    // since the block is not available so I need to remove last element (least recently used),
    // shift each element to right by one and insert the new element.
    int i;
    for (i = c_size-2; i >= 0; --i)
    {
        aux[i+1] = aux[i];
    }
    aux[0] = next;
    (*faultCnt)++;
}

void initializeAux(char* aux, int c_size)
{
    int i;
    for (i = 0; i < c_size; ++i)
        aux[i] = -1;
}

int main()
{
    char *str = malloc(100);
    printf("\nEnter the reference string\n");
    scanf("%100s", str); // no need to accept chars after space

    printf("\n%s\n", str);

    int len = strlen(str);

    int c_size = 0;
    printf("\nEnter size of cache\n");
    scanf("%d", &c_size);

    if (c_size < len)
    {
        int faultCnt = 0;
        char *aux = malloc(c_size);
        initializeAux(aux, c_size);

        int i;
        for (i = 0; i < len; ++i)
        {
            replaceBlock(aux, str[i], c_size, &faultCnt);
            printAux(aux, c_size);
        }

        printf("\npage fault count = %d\n", faultCnt);
    }
    return 0;
}
