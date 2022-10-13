#include <cs50.h>
#include <stdio.h>

void printingRow(int row, int pyraHeight);
void printingHex(int rowNum);

int main(void)
{
    bool state = true;
    int pyraHeight = 0;
    // checks user input to be 1-8
    while (state)
    {
        pyraHeight = get_int("Height: ");
        if ((pyraHeight >= 1) && (pyraHeight <= 8))
        {
            state = false;
        }
    }
    // For each row
    for (int rowNum = 1; rowNum <= pyraHeight; rowNum++)
    {
        printingRow(rowNum, pyraHeight);
    }
}

// print # based on row number
void printingRow(int rowNum, int pyraHeight)
{
    int whitespace = pyraHeight - rowNum + 1;
    char hex = '#';
    // print whitespace and first # on left hand side
    printf("%*c", whitespace, hex);
    // print rest of # on left hand side
    printingHex(rowNum);
    // print whitespace and first # on left hand side
    printf("%*c", 2, hex);
    // print rest of # on right hand side
    printingHex(rowNum);
    printf("\n");
}

void printingHex(int rowNum)
{
    if (rowNum > 1)
    {
        for (int i = 1; i < rowNum; i++)
        {
            printf("#");
        }
    }
}