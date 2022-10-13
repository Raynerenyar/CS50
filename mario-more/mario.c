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
        // for each # in row on left hand side
        for (int j = row; j > 0; j--)
        {
            printf("#");
        }
        printf(" ");
        printf(" ");
        // for each # in row on right hand side
        // for (int l = i; l > 0; l--)
        // {
        //     printf("#");
        // }
        printHex(row);
        printf("\n");
    }
}

void printHex(int row)
{
    for (int m = row; m > 0; m--)
    {
        printf("#");
    }
}