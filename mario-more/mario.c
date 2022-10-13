#include <cs50.h>
#include <stdio.h>

void printHex(int row);

int main(void)
{
    int getHeight = get_int("Height: ");
    // For row by row
    int rowNum = 0;
    for (rowNum = 1; rowNum <= getHeight; rowNum++)
    {
        // for each whitespace in rowNum on left hand side
        int numOfWhitespace = getHeight - rowNum;
        for (int i = numOfWhitespace; i > 0; i--)
        {
            printf(" ");
        }
        // for each hex in rowNum on left hand side
        printHex(rowNum);

        printf(" ");
        printf(" ");

        // for each hex in rowNum on left hand side
        printHex(rowNum);

        // next line
        printf("\n");
    }
}

// print # based on rowNum number
void printHex(int rowNum)
{
    for (int k = rowNum; k > 0; k--)
    {
        printf("#");
    }
}