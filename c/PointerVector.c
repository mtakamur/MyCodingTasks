#include <stdio.h>

int main(void)
{
    int i = 0;
    char *str[] = {"My", "name", "is", "Masahiro", NULL};

    for(i=0; str[i]!=NULL; i++)
    {
        printf("str[%d] %p: %s\n", i, str[i], str[i]);
    }
    return 0;
}