#include <cs50.h>
#include <stdio.h>

void printHex(int row);

int main(void)
{
    int getHeight = get_int("Height: ");
    // For row by row
    int row = 0;
    for (row = 1; row <= getHeight; row++)
    {
        // for each whitespace in row on left hand side
        int numOfWhitespace = getHeight - row;
        for (int i = numOfWhitespace; i > 0; i--)
        {
            printf(" ");
        }
        printHex(row);
        printf(" ");
        printf(" ");
        printHex(row);
        printf("\n");
    }
}

void printHex(int row)
{
    for (int k = row; k > 0; k--)
    {
        printf("#");
    }
}