#include <stdio.h>
#include <stdlib.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Only 1 command-line argument is allowed\n");
        return 1;
    }
    char *forensicImage = argc[1];

    // open memory card
    FILE *raw = fopen(forensicImage, 'r');
    bool reading = true;
    // repeat until end of card:
    while (reading)
    {
        fread()
        // read 512 bytes into buffer
        for ()
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