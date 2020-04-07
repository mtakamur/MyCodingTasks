#include <stdio.h>
#include <string.h>

#define PI 3.14
#if defined(PI)
    #define PRINT_PI printf("Pi = %3.2f\n", PI)
#endif

#define LONG_MACRO\
    printf("Test\n");\
    printf("Tes\n");\
    printf("Te\n");\
    printf("T\n")\

int main(int argc, char* argv[])
{
    printf("Pi = %3.2f\n", PI);// PI is still existing
    PRINT_PI;
    LONG_MACRO;
    #undef PI
    //printf("Pi = %3.2f\n", PI);// No definition of PI. ERROR!
    return 0;
}