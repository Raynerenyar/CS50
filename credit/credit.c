#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int firstArrLen = (count/2);
    int secArrLen = (count - (count/2));
    int firstArray[firstArrLen];
    int secondArray[secArrLen];
    int i = count;
    int whichArray = 2;
    int k = 0;
    int l = 0;
    // int i = count; i > 0; i--
    while (i > 0)
    {
        if (whichArray ==  1)
        {
            firstArray[k] = num%10;
            num /= 10;
            whichArray = 2;
            printf("%i   %i",i, firstArray[k]);
            k++;
        }
        else
        {
            secondArray[l] = num%10;
            num /= 10;
            whichArray = 1;
            printf("%i   %i",i, secondArray[l]);
            l++;
        }
        i -= 1;
        // printf("\n");
    }
    int sum = 0;
    for (int a = 0; a < secArrLen; a++)
    {
        secondArray[a] *= 2;
        sum += secondArray[a];
    }
    int finalSum = 0;
    for (int b = 0; b < firstArrLen; b++)
    {
        finalSum += firstArray[b];
    }
    printf("%i",(sum+finalSum));



    // check nums in first array
    // printf("first array\n");
    // for (int m = 0; m < firstArrLen; m++)
    // {
    //     printf("%i %i\n", m,firstArray[m]);
    // }
    // printf("\n");
    // // check nums in second array
    // printf("second array\n");
    // for (int n = 0; n < secArrLen; n++)
    // {
    //     printf("%i %i\n", n, secondArray[n]);
    // }
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}