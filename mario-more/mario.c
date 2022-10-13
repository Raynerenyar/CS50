#include <cs50.h>
#include <stdio.h>

// void block(int height);

int main(void)
{
    int getHeight = get_int("Height: ");
    // For row by row
    for (int i = 1; i = getHeight; i++)
    {
        // for each whitespace in row
        int numOfWhitespace = getHeight - i;
        for (int j = numOfWhitespace; j > 0; j--)
        {
            printf("\s");
        }
        // for each # in row
        for (int k = i; k = getHeight; k++)
        {
            printf("#");
        }
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