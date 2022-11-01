#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #include <cs50.h>

typedef uint8_t BYTE;
int check_signature(BYTE signature[4]);

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
        int counter = 0;
        // read 512 bytes into buffer
        for (int i = 0; i < 4; i ++)
        {
            fread(signature, 4, 1, raw);
            if (check_signature(signature) == 1) // 1 if jpeg signature found
            {
                // create image
                char filename[7];
                sprintf(filename, "%03i.jpg", counter);
                FILE *outptr = fopen(filename, "w");
                fwrite(signature, 4, 1, outptr);

            }
            else
            {
                // read rest of block
                fread(&jpeg_data, 512 - 4, 1, raw);
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

int check_signature(BYTE signature[4])
{
    if ( signature[0] == 0xff && signature[1] == 0xd8 && signature[2] == 0xff && (signature[3] & 0xf0) == 0xe0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}