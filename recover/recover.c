#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Only 1 command-line argument is allowed\n");
        return 1;
    }
    char *forensicImage = argv[1];

    // open memory card
    FILE *raw = fopen(forensicImage, "r");
    int reading = 1;
    // jpeg image header
    BYTE signature;
    // repeat until end of card:
    while (reading)
    {
        // read 512 bytes into buffer
        for (int i = 0; i < 4; i ++)
        {
            fread(&signature, 1, 1, raw);
            break;
        }
    }
        // if start of a new jpeg
            // if first jpeg
                // write to new file with ###.jpg
            // else
                // close file
        // else
            // if already found jpeg
                // ...
    // close any remaining files

}