#include <cs50.h>
#include <stdio.h>

void block(int height);

int main(void)
{
    int getHeight = get_int("Height: ");
    block(getHeight);
}

void block(int height)
{
    printf("test %i\n", height);
    printf("n");
    printf(" ");
    printf("n\n");
}