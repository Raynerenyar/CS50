#include <cs50.h>
#include <stdio.h>

void printingHex(int row);

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
    printf("%*i\n", 3, pyraHeight);
    // For each row
    for (int rowNum = 1; rowNum <= pyraHeight; rowNum++)
    {
        // for each whitespace in row on left hand side
        int numOfWhitespace = pyraHeight - rowNum;

        // next line
        printf("\n");
    }
}

// print # based on row number
void printingHex(int rowNum, int pyraHeight)
{
    for (int k = rowNum; k > 0; k--)
    {
        printf("#");
    }
}