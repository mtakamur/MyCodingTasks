#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc == 1) printf("No option detected.\n");

    while(argc > 0)
    {// Get all the options
        argc--;

        if(argv[argc][0] == '-')
        {// Read option
            //printf("Parameter no.%d = %s\n", argc, argv[argc]);
            //if(argv[argc][1] == 'a') printf("Option \"a\" detected\n");
            //else if(argv[argc][1] == 'b') printf("Option \"b\" detected\n");
            //else if(argv[argc][1] == 'c') printf("Option \"c\" detected\n");
            if(strcmp(argv[argc], "-a") == 0) printf("Option \"a\" detected\n");
            else if(strcmp(argv[argc], "-all") == 0) printf("Option \"all\" detected\n");
            else printf("Unknown option \"%s\"detected\n", argv[argc]);
        }
    }
    return 0;
}