#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int firstArray[(20)];
    int secondArray[(20)];
    // int i = count;
    int whichArray = 2;
    for (int i = count; i > 0; i--)
    {
        if (whichArray ==  1)
        {
            firstArray[i] = num%10;
            num /= 10;
            whichArray = 2;
            // printf("%li   %i",num, firstArray[i]);
            printf("%i",firstArray[i]);
            // printf("\n");
            // printf(" %li\n",num);
        }
        else
        {
            secondArray[i] = num%10;
            num /= 10;
            whichArray = 1;
            // printf("%li   %i",num, secondArray[i]);
            printf("%i",secondArray[i]);
            // printf("\n");
            // printf(" %li\n",num);
        }
        printf("\n");
    }
    // printf("%i\n", firstArray[8]);
    // // check nums in first array
    // for (int j = 0; j < count; j++)
    // {
    //     printf("%i %i\n", j,firstArray[j]);
    // }
    // printf("\n");
    // // check nums in second array
    // for (int k = 0; k < count; k++)
    // {
    //     printf("%i %i\n", k, secondArray[k]);
    // }
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}