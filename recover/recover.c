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
    if (argc < 2)
    {
        printf("Usage: ./recover card.raw\n");
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
    int counter = 0;
    while (reading > 0)
    {
        // read 1 block of buffer
        // read first 4 bytes of buffer for jpeg signature
        reading = fread(signature, 4, 1, raw);
        if (check_signature(signature) == 0) // 0 if jpeg signature found
        {
            // create image
            char filename[8];
            sprintf(filename, "%03i.jpg", counter); // %03 - inputs 3 digits including leading 0s
            FILE *outptr = fopen(filename, "w");
            fwrite(signature, 4, 1, outptr);
            fread(&jpeg_data, 512 - 4, 1, raw);
            fwrite(jpeg_data, 512 - 4, 1, outptr);
            int same_image = 1;
            while (same_image == 1)
            {
                fread(signature, 4, 1, raw);
                if (check_signature(signature) != 0)
                {
                fwrite(signature, 4, 1, outptr);
                fread(&jpeg_data, 512 - 4, 1, raw);
                fwrite(jpeg_data, 512 - 4, 1, outptr);
                }
                else
                {
                    fclose(outptr);
                    counter++;
                    same_image = 0;
                }
            }
        }
        else
        {
            // read rest of block
            fread(&jpeg_data, 512 - 4, 1, raw);
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
    fclose(raw);
}

int check_signature(BYTE signature[4])
{
    if ( signature[0] == 0xff && signature[1] == 0xd8 && signature[2] == 0xff && (signature[3] & 0xf0) == 0xe0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}