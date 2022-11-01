#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int check_signature(BYTE signature);

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
    BYTE signature[4];
    BYTE jpeg_data[512 - 4];
    // repeat until end of card:
    // while (reading)
    // {
        // read 512 bytes into buffer
        for (int i = 0; i < 4; i ++)
        {
            fread(&signature, 4, 1, raw);
            if (check_signature == 1
            {
                // create image
            }
            else
            {
                // read rest of block
                fread(&jpeg_data, 512 - 4, 1 raw);
            }
        }
    // }
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

int check_signature(BYTE signature)
{
    for (int j = 0; j < 4; j++)
    {
        if (signature[i] == 0xff)
        {
            continue;
        }
        if (signature[i] == 0xd8)
        {
            continue;
        }
        if (signature[i] == 0xff)
        {
            continue;
        }
        if ( (signature[i] & 0xf0) == 0xe0 )
        {
            return 1;
        }

    }
}