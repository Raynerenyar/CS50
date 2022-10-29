// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    // uint8_t *header = malloc(HEADER_SIZE + 1);
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // else
    // {
    //     for (int i = 0; i < HEADER_SIZE + 1; i++)
    //     {
    //         header[i] = input[i];
    //     }
    // }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE + 1];
    while (fread(header, sizeof(header), 1, input))
    {
        fwrite(header, sizeof(header), 1, output);
    }

    // TODO: Read samples from input file and write updated data to output file
    uint16_t buffer;
    while (fread(sample, sizeof(sample), 1, input))
    {
        fwrite(sample*2, sizeof(sample), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
