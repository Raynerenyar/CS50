#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// def datatype
typedef uint8_t BYTE;
// def function
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
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open memory card
    char *forensicImage = argv[1];
    FILE *raw = fopen(forensicImage, "r");
    int reading = 1;
    // jpeg image header
    BYTE signature[4];
    BYTE jpeg_data[512 - 4];

    // image file counter
    int counter = 0;

    // read first 4 bytes of buffer for jpeg signature
    reading = fread(signature, 4, 1, raw);

    // in each loop, reads 4 + 508 bytes of each block
    while (reading > 0)
    {
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

            // loops if next block does not contain jpeg signature
            while (same_image == 1)
            {
                reading = fread(signature, 4, 1, raw);
                if (check_signature(signature) != 0 && reading > 0)
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
        // jpeg signature not found, read rest of the 508 bytes
        else
        {
            // read rest of block
            fread(&jpeg_data, 512 - 4, 1, raw);

            // if reading < 0, breaks while loop
            reading = fread(signature, 4, 1, raw);
        }
    }
    fclose(raw);
    return 0;
}

// check if signature exists
int check_signature(BYTE signature[4])
{
    if (signature[0] == 0xff && signature[1] == 0xd8 && signature[2] == 0xff && (signature[3] & 0xf0) == 0xe0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}