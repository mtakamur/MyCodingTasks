#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *ifile = 0x0;
    int read_buff[5] = {0};

    printf("Name of this application is %s\n", argv[0]);
    printf("Number of parameters = %d\n", argc);

    if (argv[1] == 0)
    {
        printf("No file name input\n");
        printf("Exit with an error...\n");
        return -1;
    }
    else
    {
        printf("%s will be opened\n", argv[1]);
        ifile = fopen(argv[1], "rb");
        if (ifile)
        { // When the datafile exists
            printf("Pointer to \"%s\" = %p\n", argv[1], ifile);
        }
        else
        { // When the datafile couldn't be opened
            printf("Couldn't open \"%s\"\n", argv[1]);
        }
    }

    /////////////////////////////
    // Read value from datafile//
    /////////////////////////////
    fread(read_buff, sizeof(int), 5, ifile);
    printf("Values read from datafile \"%s\" = \n", argv[1]);
    for (int i = 0; i < 5; i++)
    {
        if (i != 4)
        {
            printf("%d,", read_buff[i]);
        }
        else
        {
            printf("%d\n", read_buff[i]);
        }
    }

    printf("Closing datafile \"%s\"\n", argv[1]);
    fclose(ifile);
    return 0;
}