#include <cs50.h>
#include <stdio.h>

void printHex(int row);

int main(void)
{
    int getHeight = get_int("Height: ");
    // For row by row
    int i = 0;
    for (i = 1; i <= getHeight; i++)
    {
        // for each whitespace in row on left hand side
        int numOfWhitespace = getHeight - i;
        for (int j = numOfWhitespace; j > 0; j--)
        {
            printf(" ");
        }
        // for each # in row on left hand side
        for (int k = i; k > 0; k--)
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
        printHex(i);
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