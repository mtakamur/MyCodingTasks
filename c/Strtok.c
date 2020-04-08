#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int SIZE = 32;
    char raw_data[SIZE] = "0, 1, 2, 3, 4, 5";
    char *buffer;
    int value[32];
    int i, j;

    buffer = strtok(raw_data, ",");
    
    for(i=0; i<SIZE; i++)
    {
        if(buffer == NULL)
        {
            break;
        }
        else
        {
            value[i] = atoi(buffer);
        }
        buffer = strtok(NULL, ",");
    }

    for(int j=0; j<i; j++)
    {
        printf("%d\n", value[j]);
    }
    return 0;
}