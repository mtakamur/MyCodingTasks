#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char* MY_NAME = "Masahiro";
    int buffer[5] = {1, 2, 3, 4, 5};

    FILE *norm_file = 0x0;// Pointer to a file in normal mode
    FILE *bin_file = 0x0;// Pointer to a file in binary mode
    norm_file = fopen("normal_file.dat", "w");
    bin_file = fopen("binary_file.dat","wb");

    printf("Name of this program is %s\n", argv[0]);

    fprintf(norm_file, "Hello, world from %s", MY_NAME);// Write string in normal file

    //fwrite(MY_NAME, sizeof(MY_NAME), 1, bin_file);
    fwrite(&buffer, sizeof(int), 5, bin_file);
    fwrite(&buffer, sizeof(buffer), 1, bin_file); // Same as the above
    /*
        Written data size is calculated as
        (sizeof) * (number of data)
    */

    fclose(norm_file);
    fclose(bin_file);
    return 0;
}