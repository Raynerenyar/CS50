#include <cs50.h>
#include <stdio.h>

void printingHex(int row, int pyraHeight);

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
        printingHex(rowNum, pyraHeight);
    }
}

// print # based on row number
void printingHex(int rowNum, int pyraHeight)
{
    int whitespace = pyraHeight - rowNum;
    char hex = '#';
    printf("%*c", whitespace, hex);
    if (rowNum > 1)
    {
        for (int i = 0; i < rowNum; i++ )
        {
            printf("#");
        }
    }
    printf("%*c\n", 2, hex);
}