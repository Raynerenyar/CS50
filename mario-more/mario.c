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
        printHex()
        printf("\n");
    }
}

void printHex(int row)
{
    for (int row = i; row > 0; row--)
    {
        printf("#");
    }
}

// void block(int height)
// {
//     printf("test %i\n", height);
//     for (int i = 0; i < h; i++)
//     {
//         printf("#");
//     }
//     for (int h)
//     printf("\n");
// }

// void printWhitespace(int row)
// {
//     for (int i = row; i > 0; i--)
//     {

//     }
// }