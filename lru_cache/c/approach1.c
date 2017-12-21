#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getAuxArray(char* str, int c_size)
{
    char *aux = malloc(sizeof(char)*c_size);
    int i;

    /* in the aux array we should insert from the end because, we need to make sure
    that the least recently used element should be at the end and most recently used element should be at front*/
    for (i = 0; i < c_size; ++i)
        aux[c_size-1-i] = str[i];

    return aux;
}

void printAux(char *aux, int c_size)
{
    printf("\n");
    int i;
    for (i = 0; i < c_size; ++i)
    {
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

void replaceBlock(char* aux, char next, int c_size)
{
    int isBlockAvailable = findOutBlock(aux, next, c_size);

    if (isBlockAvailable)
    {
        return;
    }
    // since the block is not available so I need to remove last element (least recently used),
    // shift each element to right by one and insert the new element.
    int i;
    for (i = c_size-2; i >= 0; --i)
    {
        aux[i+1] = aux[i];
    }
    aux[0] = next;
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
        char *aux = getAuxArray(str, c_size);

        int i;
        for (i = c_size; i < len; ++i)
        {
            replaceBlock(aux, str[i], c_size);
        }

        printAux(aux, c_size);
    }
    return 0;
}
