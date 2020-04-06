#include <stdio.h>
#include <string.h>

int main(void)
{
    const char* MY_NAME = "Masahiro";
    FILE *file = 0x0;
    file = fopen("test.dat", "wb");

    fprintf(file, "Hello file from %s", MY_NAME);

    fclose(file);
    return 0;
}