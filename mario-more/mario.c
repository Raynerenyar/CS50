#include <cs50.h>
#include <stdio.h>

void printHex(int row);

int main(void)
{
    int pyraHeight = get_int("Height: ");
    // For each row
    for (int rowNum = 1; rowNum <= pyraHeight; rowNum++)
    {
        // for each whitespace in row on left hand side
        int numOfWhitespace = pyraHeight - rowNum;
        for (int i = numOfWhitespace; i > 0; i--)
        {
            printf(" ");
        }
        // for each hex in row on left hand side
        printHex(rowNum);

        printf(" ");
        printf(" ");

        // for each hex in row on left hand side
        printHex(rowNum);

        // next line
        printf("\n");
    }
}

// print # based on row number
void printHex(int rowNum)
{
    for (int k = rowNum; k > 0; k--)
    {
        printf("#");
    }
}