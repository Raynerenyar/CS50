#include <cs50.h>
#include <stdio.h>

// void block(int height);

int main(void)
{
    int getHeight = get_int("Height: ");
    printf("%i\n", getHeight);
    // For row by row
    int i = 0;
    for (i = 1; i <= getHeight; i++)
    {
        // printf("for row by row: %i\n",i);
        // for each whitespace in row
        int numOfWhitespace = getHeight - i;
        for (int j = numOfWhitespace; j > 0; j--)
        {
            printf(" ");
        }
        // for each # in row
        for (int k = i; k < getHeight; k++)
        {
            printf("#");
        }
        printf("\n");
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